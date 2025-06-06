/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/* -*-c++-*- */

#ifndef LIB_EXCEPTIONS_H_
#define LIB_EXCEPTIONS_H_

#include <unistd.h>

#include <exception>

#include <boost/format.hpp>

#include "absl/strings/str_cat.h"
#include "lib/bug_helper.h"

namespace P4::Util {

// colors to pretty print messages
// \e is non-standard escape sequence, use codepoint \33 instead
constexpr char ANSI_RED[] = "\33[31m";
constexpr char ANSI_BLUE[] = "\33[34m";
constexpr char ANSI_CLR[] = "\33[0m";

/// Checks if stderr is redirected to a file
/// Check is done only once and then saved to a static variable
inline bool is_cerr_redirected() {
    static bool initialized(false);
    static bool is_redir;
    if (!initialized) {
        initialized = true;
        is_redir = ttyname(fileno(stderr)) == nullptr;  // NOLINT(runtime/threadsafe_fn)
    }
    return is_redir;
}

/// Function used to delete color in case of cerr output being redirected
inline const char *cerr_colorize(const char *color) {
    if (is_cerr_redirected()) {
        return "";
    }
    return color;
}

/// Used to clear colors on terminal
inline const char *cerr_clear_colors() {
    if (is_cerr_redirected()) {
        return "";
    }
    return ANSI_CLR;
}

/// Base class for all exceptions.
/// The constructor uses boost::format for the format string, i.e.,
/// %1%, %2%, etc (starting at 1, not at 0)
class P4CExceptionBase : public std::exception {
 protected:
    std::string message;
    void traceCreation() {}

 public:
    template <typename... Args>
    explicit P4CExceptionBase(const char *format, Args &&...args) {
        traceCreation();
        boost::format fmt(format);
        // FIXME: This will implicitly take location of the first argument having
        // SourceInfo. Not sure if this always desireable or not.
        message = ::P4::bug_helper(fmt, "", "", std::forward<Args>(args)...);
    }

    const char *what() const noexcept override { return message.c_str(); }
};

/// This class indicates a bug in the compiler
class CompilerBug final : public P4CExceptionBase {
 public:
    template <typename... Args>
    explicit CompilerBug(const char *format, Args &&...args)
        : P4CExceptionBase(format, std::forward<Args>(args)...) {
        // Check if output is redirected and if so, then don't color text so that
        // escape characters are not present
        message = absl::StrCat(cerr_colorize(ANSI_RED), "Compiler Bug", cerr_clear_colors(), ":\n",
                               message);
    }

    template <typename... Args>
    CompilerBug(int line, const char *file, const char *format, Args &&...args)
        : P4CExceptionBase(format, std::forward<Args>(args)...) {
        message = absl::StrCat("In file: ", file, ":", line, "\n", cerr_colorize(ANSI_RED),
                               "Compiler Bug", cerr_clear_colors(), ": ", message);
    }
};

/// This class indicates an unimplemented feature in the compiler
class CompilerUnimplemented final : public P4CExceptionBase {
 public:
    template <typename... Args>
    explicit CompilerUnimplemented(const char *format, Args &&...args)
        : P4CExceptionBase(format, std::forward<Args>(args)...) {
        // Do not add colors when redirecting to stderr
        message = absl::StrCat(cerr_colorize(ANSI_BLUE), "Not yet implemented", cerr_clear_colors(),
                               ":\n", message);
    }

    template <typename... Args>
    CompilerUnimplemented(int line, const char *file, const char *format, Args &&...args)
        : P4CExceptionBase(format, std::forward<Args>(args)...) {
        message =
            absl::StrCat("In file: ", file, ":", line, "\n", cerr_colorize(ANSI_BLUE),
                         "Unimplemented compiler support", cerr_clear_colors(), ": ", message);
    }
};

/// This class indicates a compilation error that we do not want to recover from.
/// This may be due to a malformed input program.
class CompilationError : public P4CExceptionBase {
 public:
    template <typename... Args>
    explicit CompilationError(const char *format, Args &&...args)
        : P4CExceptionBase(format, std::forward<Args>(args)...) {}
};

/// FIXME: Use __VA_OPT__ for calls without an input string?
#define BUG(...)                                                      \
    do {                                                              \
        throw P4::Util::CompilerBug(__LINE__, __FILE__, __VA_ARGS__); \
    } while (0)
#define BUG_CHECK(e, ...)           \
    do {                            \
        if (!(e)) BUG(__VA_ARGS__); \
    } while (0)
#define P4C_UNIMPLEMENTED(...)                                                  \
    do {                                                                        \
        throw P4::Util::CompilerUnimplemented(__LINE__, __FILE__, __VA_ARGS__); \
    } while (0)

}  // namespace P4::Util

/// Report an error and exit
#define FATAL_ERROR(...)                               \
    do {                                               \
        throw P4::Util::CompilationError(__VA_ARGS__); \
    } while (0)

#endif /* LIB_EXCEPTIONS_H_ */
