<!--!
\page repository_structure P4C Repository Organization                                                               
-->
<!-- 
Documentation Inclusion:
This README is integrated as a standalone page in the P4 compiler documentation.

Refer to the full page here: [P4C Repository Organization](https://p4lang.github.io/p4c/repository_structure.html)
-->
<!--!
\internal
-->
# P4C Repository Organization
<!--!
\endinternal
-->
<!--!
[TOC]
-->
This folder contains documentation for the P4_16 prototype compiler.
The code and documentation are hosted in the [p4c repository](https://github.com/p4lang/p4c). 

# Compiler source code organization

```
p4c
├── build                          -- recommended place to build binary
├── backends          
│   ├── bmv2                       -- behavioral model version 2 (switch simulator) back end
│   ├── common                     -- code shared by multiple back ends
│   ├── dpdk                       -- translates P4 code to DPDK instructions
│   ├── ebpf                       -- extended Berkeley Packet Filters back end
│   ├── graphs                     -- backend that can draw graphiz graphs of P4 programs
│   ├── p4test                     -- "fake" back end for testing
│   ├── p4tools                    -- testing library for different static analysis tools
│   ├── tc                         -- translates P4 code to Linux TC rules
│   └── ubpf                       -- translates P4 programs to uBPF code
├── bazel                          -- bazel files for building p4c
|   └──example                     -- basic Bazel project example using p4c
├── cmake                          -- CMake support and build systems 
├── control-plane                  -- control plane API
|   └──google/rpc                  -- Definitions of Google Protobuf APIs.
├── debian                         -- Debian/Ubuntu packaging files
│   └── source/format              -- Specification of the packaging format
├── docs                           -- documentation
│   ├── assets                     -- p4 logos in PNG and SVG formats
│   └── doxygen                    -- documentation generation support
├── frontends
│   ├── common                     -- common front end code
│   ├── p4-14                      -- P4_14 front end
│   ├── p4                         -- P4_16 front end
│   └── parsers                    -- parser and lexer code for P4_14 and P4_16
├── ir                             -- core internal representation
├── lib                            -- common utilities (libp4toolkit.a)
├── midend                         -- code that may be useful for writing mid-ends
├── p4include                      -- standard P4 files needed by the compiler (e.g., core.p4)
│   ├── bmv2                       -- bmv2 specific customizations of psa.p4 include file
│   ├── dpdk                       -- dpdk specific pna.p4 & psa.p4
│   └── tc                         -- tc specific pna
├── test                           -- test code
│   └── gtest                      -- unit test code written using gtest
├── testdata                       -- test inputs and reference outputs
│   ├───extern_modules             -- Extern module input test programs
│   ├───p4_14_errors               -- P4_14 negative input test programs
│   ├───p4_14_errors_outputs       -- Expected outputs from P4_14 negative tests
│   ├───p4_14_samples              -- P4_14 input test programs
│   ├───p4_14_samples_outputs      -- Expected outputs from P4_14 tests
|   ├── p4_16_samples              -- P4_16 input test programs
|   ├── p4_16_samples_outputs      -- Expected outputs from P4_16 tests
│   ├───p4_16_bmv_errors           -- P4_16 negative input tests for the bmv2 backend
│   ├───p4_16_dpdk_errors          -- P4_16 negative input tests for the dpdk backend
│   ├───p4_16_dpdk_errors_outputs  -- Expected outputs from dpdk negative tests 
│   ├───p4_16_ebpf_errors          -- P4_16 negative input tests for the ebpf backend
│   ├───p4_16_ebpf_errors_outputs  -- Expected outputs from edpf negative tests 
|   ├── p4_16_errors               -- P4_16 negative input test programs
|   ├── p4_16_errors_outputs       -- Expected outputs from P4_16 negative tests
│   ├───p4_16_pna_errors           -- P4_16 negative input test programs for pna
│   ├───p4_16_pna_errors_outputs   -- Expected outputs from P4_16 pna negative tests
│   ├───p4_16_psa_errors           -- P4_16 negative input test programs for psa
│   ├───p4_16_psa_errors_outputs   -- Expected outputs from P4_16 psa negative tests
│   ├───p4_16_samples              -- P4_16 input test programs
│   ├───p4_16_samples_outputs      -- Expected outputs from P4_16 tests
│   ├───p4tc_samples               -- P4 traffic control sample input test programs
│   ├───p4tc_samples_outputs       -- Expected outputs from P4 traffic control tests
│   └───v1_1_samples               -- P4 v1.1 sample programs
└── tools                          -- external programs used in the build/test process
    ├── ci-ptf                     -- scripts to run PSA PTF tests
    ├── debian-build               -- resources and scripts for creating Ubuntu (or Debian) packages
    ├── driver                     -- P4C compiler driver: a script that invokes various compilers
    ├── hooks                      -- useful git hooks for development
    ├── ir-generator               -- code to generate the P4C IR from .def files
    ├── iwyu_mappings              -- mappings used by the Include What You Use (IWYU) tool for analyzing #include directives in C and C++ source files
    ├── ptf                        -- utilities for the Packet Test Framework (PTF)
    └── stf                        -- utilities for the Simple Test Framework (STF)

```

# Additional documentation

* the P4_14 and P4_16 languages are described in their respective
  specifications, available [here](https://p4.org/specs).

* the core design of the compiler intermediate representation (IR) and
  the visitor patterns are briefly described in [IR](IR.md)

* The [migration guide](https://github.com/p4lang/p4c/blob/main/docs/migration-guide.pptx) describes how P4_14 (v1.0)
  programs are translated into P4_16 programs

* The [compiler design](https://github.com/p4lang/p4c/blob/main/docs/compiler-design.pptx) describes the salient
  features of the compiler design and implementation; this document has several subsections:
  * Compiler goals
  * Compiler architecture
  * Source code organization
  * IR and visitors; recipes
  * A guide to the existing passes
  * Discussion of the three sample back-ends

* Specific back-ends may have their own documentation; check the
  `extensions` sub-folders, and also the following supplied back-ends:
  * [BMv2](../backends/bmv2/README.md)
  * [eBPF](../backends/ebpf/README.md)
  * [P4Tools](../backends/p4tools/README.md)

* Check out the [IntelliJ P4 plugin](https://github.com/TakeshiTseng/IntelliJ-P4-Plugin)

# Writing documentation

Documenting the workings of the compiler is a never-ending (many times
overlooked) job. We can always write better documentation!

In P4C, documentation is generated using Doxygen. The generated documentation depends on [Doxygen Awesome CSS](https://github.com/jothepro/doxygen-awesome-css). The documentation is dynamically updated and deployed on [GitHub Pages](https://p4lang.github.io/p4c/).

Documentation is generated from two main sources: README files distributed 
across the repository and comments within the code. The README files are 
tagged with documentation inclusion notes to indicate their integration into 
the P4 compiler documentation.

Code comments should capture the main intent of the implementation and
the "why", rather than the "how". The how can be read from the code,
however, documenting the reasons why a certain implementation was
chosen will help other contributors understand the design choices and
enable them to reuse your code. Also important in the context of the
compiler is to document the invariants for each pass (or groups of
passes), since it is likely that other developers will need to insert
additional passes, and they should understand the effects that the
pass ordering has on the AST.

Documentation in the markup documents is intended for higher level
design documentation. The files will be automatically captured in the
documentation in the order implied by their naming: XX_my_doc.md where
XX is a number between 02-99. Currently, 00_revision_history.md
contains the documentation revision history, and 01_overview.md is the
overview of the compiler goals and architecture.

## C/C++ Documentation Comments Style Guide 
- Use triple slashes `///` for documenting functions and classes in files.
- Double slashes `//` should be used for "internal" comments within functions.
- Double slashes `//` should be used for inline comment.
- For rare occasions such as adding comments to multi-line macros, you may use `/* ... */` style comments.
- Formatting:
  - There should be no space at the end of the comment.
  - First letter of the comment should be a capital letter.
  - Each comment should end with a period.

## Building the Doxygen documentation
- Doxygen is configured in `docs/doxygen/doxygen.cfg`.
- The main HTML page is configured in `docs/doxygen/Doxymain.md`:
  - CSS for the card effect is in `docs/assets/css/card.css`.
  - The effect for the Easter egg toggle is defined in `docs/assets/css/flow.css`. 
  - The homepage P4C architecture is rendered using `docs/assets/architecture_unanimated.html`, with the editable draw file available at `docs/assets/Architecture.drawio`.
- Add pages and subpages manually to the sidebar (see `docs/doxygen/p4c_layout.xml`).
- TOCs in markdown files are created with the `[TOC]` command.
- The base style for Doxygen Awesome is described in the [Doxygen Awesome Documentation](https://jothepro.github.io/doxygen-awesome-css/) and the updated color scheme is defined in [`docs\assets\css\p4c_custom.css`](https://github.com/p4lang/p4c/blob/main/docs/assets/css/p4c_custom.css).

### Doxygen Comments Style Guide
- Comment Markup and Documentation Commands
  -  `<!-- ... -->` is used for adding documentation inclusion notes. This content is hidden from both the rendered Markdown and Doxygen, but visible in the raw view on GitHub.
  - Use HTML comments with an exclamation mark to add instructions for Doxygen. These comments are hidden in GitHub's Markdown but processed by Doxygen. For example:
``` 
<!--!
\page changelog Releases
-->
```
  -  `\internal` and `\endinternal` commands within comments can be used to hide information from Doxygen while still displaying it on GitHub.
```
<!--!
\internal
-->
This section is hidden from Doxygen but will be visible on GitHub.
<!--!
\endinternal
-->
```

Happy writing! Should you have any questions, please don't hesitate to ask.

## Git usage

* To contribute: fork the p4lang/p4c repository on github.  [Detailed instructions on forking a repository](https://help.github.com/articles/fork-a-repo/).
* To merge a forked repository with the latest changes in the source use:

```
git fetch upstream
git rebase upstream/main
git push -f
```

* After committing changes, create a pull request (using the github web UI)

* Follow these
  [guidelines](CodingStandardPhilosophy.md#git-commits-and-pull-requests)
  to write commit messages and open pull requests.

+ For every pull request opened, a standard set of CI tests will run
  automatically.  If any of these fail, look at the Github page for
  your pull request for the list of tests that have been run.  There
  should be "Details" links there for any tests that have failed.  Ask
  for help via messages in comments on your PR if you are not able to
  determine the cause of the failures.

+ There are several CI tests that are not run on every pull request
  automatically, but only via following the steps below, in order to
  reduce the compute resources used on every pull request.  If you
  wish to run one or more of these, look through the list of Github
  labels for the p4c project
  [here](https://github.com/p4lang/p4c/labels) for labels whose name
  begins with "run-".  Add one or more of those labels to your PR.
  On all future pushes to the branch of that PR, those additional CI
  runs should run.

## Debugging

* To debug the build process you can run `make V=1`

* The top-level `.gdbinit` file has some additional pretty-printers.
  If you start gdb in this folder (p4c), then it should be
  automatically used.  Otherwise you can run at the gdb prompt `source
  path-to-p4c/.gdbinit`.

* To debug the compiler parser you can set the environment variable
  `YYDEBUG` to 1

* The following `IR::Node` methods can be used to print nice representations of
  compiler data structures:

  * `void dbprint(std::ostream& out) const`: this method is used when
    logging information.  It should print useful debug information,
    intended for consumption by compiler writers.

  * `cstring toString() const`: this method is used when reporting
    error messages to compiler users.  It should only display
    information that is related to the P4 user program, and never
    internal compiler data structures.

* Use the LOG* macros for writing debug messages.  gdb misbehaves
  frequently, so log messages are the best way to debug your programs.
  The number in the function name is the debug verbosity.  The higher,
  the less important the message.  This macro invokes the `dbprint`
  method on objects that provide it.  Here is an example usage:
  `LOG1("Replacing " << id << " with " << newid);`

* Keep the compiler output deterministic; watch for iterators over
  sets and maps, which may introduce non-deterministic orders.  Use
  our own `ordered_map` and `ordered_set` if you iterate, to keep
  iteration order deterministic.

* You can control the logging level per compiler source-file with the
  `-T` compiler command-line flag.  The flag is followed by a list of
  file patterns and a numeric level after a colon `:`.  This flag
  enables all logging messages above the specified level for all
  compiler source files that match the file pattern.

  For example, to enable logging in file `node.cpp` above level 1, and
  in file `pass_manager.cpp` above level 2, use the following compiler
  command-line option: `-Tnode:1,pass_manager:2`

  To execute LOG statements in a header file you must supply the complete
  name of the header file, e.g.: `-TfunctionsInlining.h:3`.

## Testing

The testing infrastructure is based on small python and shell scripts.

* To run tests execute `make check -j3`
  - There should be no FAIL or XPASS tests.
  - XFAIL tests are tolerated only transiently.

* To run a subset of tests execute `make check-PATTERN`.  E.g., `make
  check-p4`.

* To rerun the tests that failed last time run `make recheck`

* To run a single test case execute `ctest --output-on-failure -R '<test>'`.
  Example: `ctest --output-on-failure -R 'psa-switch-expression-without-default'`

* Add unit tests in `test/gtest`

Test programs with file names ending in `-bmv2.p4` or `-ebpf.p4` may
have an STF (Simple Test Framework) file with file name suffix `.stf`
associated with them.  If the machine on which you are running has a
copy of `simple_switch` or the EBPF software switch installed, not
only will those programs be compiled for those targets, but also table
entries optionally specified in the STF file will be installed, and
input packets will be sent to the data plane and output packets
checked against expected packets in the STF file.

When pull requests are created on the p4c Github repository, the
changes are built, and the tests executed via `make check`.  These
tests are run with a "recently built" version of `simple_switch` from
the
[p4lang/behavioral-model](https://github.com/p4lang/behavioral-model)
repository, but it can be several hours old.  If you are working on
P4C features that rely on newly committed changes to `simple_switch`
you can find out which `simple_switch` version these P4C automated
tests are using at the link below:

+ [https://hub.docker.com/r/p4lang/behavioral-model/builds](https://hub.docker.com/r/p4lang/behavioral-model/builds)

### Adding new test data

To add a new input test with a sample P4 code file (under `testdata/p4_16_samples/` for example), one needs to:

* Add the `*.p4` file to the `testdata/p4_16_samples/` directory. The file name might determine which test suite this test belongs to. Those are determined by cmake commands.
  * For example, [any P4 file under `testdata/p4_16_samples/`](https://github.com/p4lang/p4c/blob/de2eaa085152abd0690660fbe561eaf5db7b2bf7/backends/p4test/CMakeLists.txt#L63) belongs to the [`p4` test suite](https://github.com/p4lang/p4c/blob/de2eaa085152abd0690660fbe561eaf5db7b2bf7/backends/p4test/CMakeLists.txt#L113) (meaning it will run with `make check-p4`).
  * [File ending with `*-bmv2.p4`](https://github.com/p4lang/p4c/blob/de2eaa085152abd0690660fbe561eaf5db7b2bf7/backends/bmv2/CMakeLists.txt#L127) also belongs to the [`bmv2` test suite](https://github.com/p4lang/p4c/blob/de2eaa085152abd0690660fbe561eaf5db7b2bf7/backends/bmv2/CMakeLists.txt#L200) (meaning it will run with `make check-bmv2`).
* Then generate reference outputs:
  * For a frontend-only test, you can run `../backends/p4test/run-p4-sample.py . -f ../testdata/p4_16_samples/some_name.p4`. Note that this command needs to run under the `build/` directory. The test will fail if the test output is missing or does not match with the existing reference outputs. Toggling the `-f` flag will force the script to produce new reference outputs, which can, and should be committed, along with the changes that caused the output change. 
  * For a test targeting bmv2 backend, the corresponding command is `../backends/bmv2/run-bmv2-test.py`.
  * If you have many reference outputs to add/update, you could also do `P4TEST_REPLACE=True make check` (or `make check-*`) to update all tests.
* The reference files for each test will be updated after running the tests.

## Coding conventions

* Coding style is guided by the [following rules](CodingStandardPhilosophy.md).

* We generally follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html). This is partially enforced by `cpplint` and `clang-format` and their respective configuration files. We have customized Google's `cpplint.py` tool for our purposes.  The tool can be invoked with `make cpplint`. To be able to run `clang-format` on Ubuntu 20.04, install it with `pip3 install --user clang-format`. Do not use the Debian package. Both tools run in a git hook and as part of CI.

* Commenting Style is guided by the [following rules](#documentation-comments-style-guide).
  
* Watch out for `const`; it is very important.

* Use `override` whenever possible (new GCC versions enforce this).

* Never use `const_cast` and `reinterpret_cast`.

* Lines are wrapped at 100 characters.

* Indents are four spaces. Tab characters should not be used for indenting.

* The C++ code is written to use a garbage-collector
  * do not use any smart pointers, just raw pointers
* Use our implementations and wrappers instead of standard classes:

  * Use `cstring` for constant strings.  For java programmers, `cstring`
    should be used where you would use java.lang.String, and `std::string`
    should be used where you would use StringBuilder or StringBuffer.

  * Use the `BUG()` macro to signal an exception.  This macro is
    guaranteed to throw an exception.

  * Use `CHECK_NULL()` to validate that pointers are not nullptr.

  * Use `BUG_CHECK()` instead of `assert`, and always supply an
    informative error message.

  * Use `error()` and `warning()` for error reporting. See the
    [guidelines](CodingStandardPhilosophy.md#handling-errors) for more
    details.

  * Use `LOGn()` for log messages -- the `n` is an integer constant for
    verbosity level.  These can be controlled on a per-source-file basis
    with the -T option.  LOG1 should be used for general messages, so that
    running with -T*:1 (turning on all LOG1 messages) is not too overwhelming.
    LOG2 should be used to print information about the results of a module
    that later passes may need to debug them.  Details of what a module
    or pass is doing and looking at (only of interest when debugging that
    code) should be at LOG4 or higher.

  * Use the `vector` and `array` wrappers for `std::vector` and `std::array`
    (these do bounds checking on all accesses).

  * Use `ordered_map` and `ordered_set` when you need to iterate;
    they provide deterministic iterators.

## Compiler Driver

**p4c** is a compiler driver. The goal is to provide a consistent user interface
across different p4 backends and work flows. The compiler driver is written in
Python. It can be extended for custom backends.

The usage of the driver is as follows:
```
usage: p4c [-h] [-V] [-v] [-###] [-Xpreprocessor <arg>] [-Xp4c <arg>]
           [-Xassembler <arg>] [-Xlinker <arg>] [-b BACKEND] [-E] [-e] [-S]
           [-c] [-x {p4-14,p4-16}] [-I SEARCH_PATH] [-o PATH] [--target-help]
           [source_file]

positional arguments:
  source_file           File to compile

optional arguments:
  -h, --help            show this help message and exit
  -V, --version         show version and exit
  -v                    verbose
  -###                  print (but do not run) the commands
  -Xpreprocessor <arg>  Pass <arg> to the preprocessor
  -Xp4c <arg>           Pass <arg> to the compiler
  -Xassembler <arg>     Pass <arg> to the assembler
  -Xlinker <arg>        Pass <arg> to the linker
  -b BACKEND            specify target backend
  -E                    Only run the preprocessor
  -e                    Skip the preprocessor
  -S                    Only run the preprocess and compilation steps
  -c                    Only run preprocess, compile, and assemble steps
  -x {p4-14,p4-16}      Treat subsequent input file as having type language.
  -I SEARCH_PATH        Add directory to include search path
  -o PATH               Write output to the provided path
  --target-help         Display target specific command line options.
```

To extend the driver, user needs to create a configuration file and add it to the `p4c_PYTHON`
makefile variable.

```
# In your custom Makefile.am

p4c_PYTHON += p4c.custom.cfg
```

There is an global variable `config` in the `p4c` compiler driver that stores the build steps
for a particular target. By default, the bmv2 and ebpf backends are supported. Each backend
is identified with a triplet: **target-arch-vendor**. For example, the default bmv2 backend is
identified as `bmv2-ss-p4org`. Users may choose to implement different architectures running
on the same target, and they should configure the compilation flow as follows:

```
config.add_preprocessor_options("bmv2-newarch-p4org", "-E")
config.add_compiler_options("bmv2-newarch-p4org", "{}/{}.o".format(output_dir, source_basename))
config.add_assembler_options("bmv2-newarch-p4org", "{}/{}.asm".format(output_dir, source_basename))
config.add_linker_options("bmv2-newarch-p4org", "{}/{}.json".format(output_dir, source_basename))

config.add_toolchain("bmv2-newarch-p4org", {"preprocessor": "cc", "compiler": "p4c-bm2-newarch", "assembler": "", "linker": ""})
config.add_compilation_steps(["preprocessor", "compiler"])
config.target.append("bmv2-newarch-p4org")
```

After adding the new configuration file, rerun `bootstrap.sh`

For testing purposes, `p4c` will be installed in the build/ directory when executing `make`.
Users can install `p4c` to other system path by running `make install`
