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

#ifndef IR_INDEXED_VECTOR_H_
#define IR_INDEXED_VECTOR_H_

#include "ir/declaration.h"
#include "ir/vector.h"
#include "lib/enumerator.h"
#include "lib/error.h"
#include "lib/map.h"
#include "lib/null.h"
#include "lib/safe_vector.h"
#include "lib/string_map.h"

namespace P4 {
class JSONLoader;
}  // namespace P4

namespace P4::IR {

/**
 * A Vector which holds objects which are instances of IDeclaration, and keeps
 * an index so that they can be quickly looked up by name.
 */
template <class T>
class IndexedVector : public Vector<T> {
    string_map<const IDeclaration *> declarations;
    bool invalid = false;  // set when an error occurs; then we don't
                           // expect the validity check to succeed.

    void insertInMap(const T *a) {
        if (a == nullptr || !a->template is<IDeclaration>()) return;
        auto decl = a->template to<IDeclaration>();
        auto name = decl->getName().name;
        auto [it, inserted] = declarations.emplace(name, decl);
        if (!inserted) {
            invalid = true;
            ::P4::error(ErrorType::ERR_DUPLICATE, "%1%: Duplicates declaration %2%", a, it->second);
        }
    }
    void removeFromMap(const T *a) {
        if (a == nullptr) return;
        auto decl = a->template to<IDeclaration>();
        if (decl == nullptr) return;
        cstring name = decl->getName().name;
        auto it = declarations.find(name);
        if (it == declarations.end()) BUG("%1% does not exist", a);
        declarations.erase(it);
    }

 public:
    using Vector<T>::begin;
    using Vector<T>::end;

    IndexedVector() = default;
    IndexedVector(const IndexedVector &) = default;
    IndexedVector(IndexedVector &&) = default;
    IndexedVector(std::initializer_list<const T *> a) : Vector<T>(a) {
        for (auto el : *this) insertInMap(el);
    }
    IndexedVector &operator=(const IndexedVector &) = default;
    IndexedVector &operator=(IndexedVector &&) = default;
    explicit IndexedVector(const T *a) { push_back(a); }
    explicit IndexedVector(const safe_vector<const T *> &a) {
        insert(Vector<T>::end(), a.begin(), a.end());
    }
    explicit IndexedVector(const Vector<T> &a) { insert(Vector<T>::end(), a.begin(), a.end()); }
    template <typename It>
    explicit IndexedVector(It start, It end) {
        insert(Vector<T>::end(), start, end);
    }
    explicit IndexedVector(JSONLoader &json);

    void clear() {
        IR::Vector<T>::clear();
        declarations.clear();
    }
    // TODO: Although this is not a const_iterator, it should NOT
    // be used to modify the vector directly.  I don't know
    // how to enforce this property, though.
    using iterator = typename Vector<T>::iterator;
    using const_iterator = typename Vector<T>::const_iterator;

    const IDeclaration *getDeclaration(cstring name) const {
        auto it = declarations.find(name);
        if (it == declarations.end()) return nullptr;
        return it->second;
    }
    const IDeclaration *getDeclaration(std::string_view name) const {
        auto it = declarations.find(name);
        if (it == declarations.end()) return nullptr;
        return it->second;
    }
    template <class U>
    const U *getDeclaration(cstring name) const {
        auto it = declarations.find(name);
        if (it == declarations.end()) return nullptr;
        return it->second->template to<U>();
    }
    template <class U>
    const U *getDeclaration(std::string_view name) const {
        auto it = declarations.find(name);
        if (it == declarations.end()) return nullptr;
        return it->second->template to<U>();
    }
    Util::Enumerator<const IDeclaration *> *getDeclarations() const {
        return Util::enumerate(Values(declarations));
    }
    iterator erase(iterator from, iterator to) {
        for (auto it = from; it != to; ++it) {
            removeFromMap(*it);
        }
        return Vector<T>::erase(from, to);
    }
    iterator erase(iterator i) {
        removeFromMap(*i);
        return Vector<T>::erase(i);
    }
    template <typename ForwardIter>
    iterator insert(iterator i, ForwardIter b, ForwardIter e) {
        for (auto it = b; it != e; ++it) insertInMap(*it);
        return Vector<T>::insert(i, b, e);
    }
    iterator replace(iterator i, const T *v) {
        removeFromMap(*i);
        *i = v;
        insertInMap(v);
        return ++i;
    }
    template <typename Container>
    iterator append(const Container &toAppend) {
        return insert(Vector<T>::end(), toAppend.begin(), toAppend.end());
    }
    template <typename Container>
    iterator prepend(const Container &toAppend) {
        return insert(Vector<T>::begin(), toAppend.begin(), toAppend.end());
    }
    iterator insert(iterator i, const T *v) {
        insertInMap(v);
        return Vector<T>::insert(i, v);
    }
    template <class... Args>
    void emplace_back(Args &&...args) {
        auto el = new T(std::forward<Args>(args)...);
        push_back(el);
    }
    bool removeByName(cstring name) {
        for (auto it = begin(); it != end(); ++it) {
            auto decl = (*it)->template to<IDeclaration>();
            if (decl != nullptr && decl->getName() == name) {
                erase(it);
                return true;
            }
        }
        return false;
    }
    void push_back(T *a) {
        CHECK_NULL(a);
        Vector<T>::push_back(a);
        insertInMap(a);
    }
    void push_back(const T *a) {
        CHECK_NULL(a);
        Vector<T>::push_back(a);
        insertInMap(a);
    }
    void pop_back() {
        if (Vector<T>::empty()) BUG("pop_back from empty IndexedVector");
        auto last = Vector<T>::back();
        removeFromMap(last);
        Vector<T>::pop_back();
    }
    template <class U>
    void push_back(U &a) {
        Vector<T>::push_back(a);
        insertInMap(a);
    }

    IRNODE_SUBCLASS(IndexedVector)
    IRNODE_DECLARE_APPLY_OVERLOAD(IndexedVector)
    bool operator==(const Node &a) const override { return a == *this; }
    bool operator==(const Vector<T> &a) const override { return a == *this; }
    bool operator==(const IndexedVector &a) const override {
        return Vector<T>::operator==(static_cast<const Vector<T> &>(a));
    }
    /* DANGER -- if you get an error on one of the above lines
     *       operator== ... marked ‘override’, but does not override
     * that mean you're trying to create an instantiation of IR::IndexedVector
     * that does not appear anywhere in any .def file, which won't work.
     * To make double-dispatch comparisons work, the IR generator must know
     * about ALL instantiations of IR class templates, which it does by scanning
     * all the .def files for instantiations.  This could in theory be fixed by
     * having the IR generator scan all C++ header and source files for
     * instantiations, but that is currently not done.
     *
     * To avoid this problem, you need to have your code ONLY use instantiations
     * of IR::IndexedVector that appear somewhere in a .def file -- you can usually
     * make it work by using an instantiation with an (abstract) base class rather
     * than a concrete class, as most of those appear in .def files. */

    cstring node_type_name() const override {
        return "IndexedVector<" + T::static_type_name() + ">";
    }
    static cstring static_type_name() { return "IndexedVector<" + T::static_type_name() + ">"; }
    void visit_children(Visitor &v, const char *name) override;
    void visit_children(Visitor &v, const char *name) const override;

    void toJSON(JSONGenerator &json) const override;
    static IndexedVector<T> *fromJSON(JSONLoader &json);
    void validate() const override {
        if (invalid) return;  // don't crash the compiler because an error happened
        for (auto el : *this) {
            auto decl = el->template to<IR::IDeclaration>();
            if (!decl) continue;
            auto it = declarations.find(decl->getName());
            BUG_CHECK(it != declarations.end() && it->second->getNode() == el->getNode(),
                      "invalid element %1%", el);
        }
    }

    DECLARE_TYPEINFO_WITH_DISCRIMINATOR(IndexedVector<T>, NodeDiscriminator::IndexedVectorT, T,
                                        Vector<T>);
};

}  // namespace P4::IR

#endif /* IR_INDEXED_VECTOR_H_ */
