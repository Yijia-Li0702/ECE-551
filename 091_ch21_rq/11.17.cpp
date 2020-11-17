#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdio>

#include "set.h"

template<typename T>
void Set<T>::add (const T & item) {
    if (contains(item)) {
        return;
    }
    set.push_back(item);
    size++;
    return;
}

template<typename T>
bool Set<T>::contains (const T & item) const {
    typename std::vector<T>::iterator it = set.begin();
    while (it != set.end()) {
        if (*it == item) {
            return true;
        }
        ++it;
    }
    return false;
}

template<typename T>
unsigned Set<T>::numItems() const {
    return size;
}

template <typename T>
void Set<T>::remove(const T & item) {
    typename std::vector<T>::iterator it = set.begin();
    while (it != set.end()) {
        if (*it == item) {
            set.erase(it);
            size--;
            return;
        }
        ++it;
    }
}

template <typename T>
Set<T> Set<T>::intersect(const Set<T> & s) const {
    Set<T> interSet;
    typename std::vector<T>::iterator it = set.begin();
    while (it != set.end()) {
        if (s.contains(*it)) {
            interSet.add(*it);
        }
        ++it;
    }
    return interSet;
}

template <typename T>
Set<T> Set<T>::unionSet(const Set<T> & s) const {
    Set<T> unionSet;
    typename std::vector<T>::iterator it1 = set.begin();
    while (it1 != set.end()) {
        unionSet.add(*it1);
        ++it1;
    }
    typename std::vector<T>::iterator it2 = s.set.begin();
    while (it2 != s.set.end()) {
        if (!unionSet.contains(*it2)) {
            unionSet.add(*it2);
        }
        ++it2;
    }
    return unionSet;
}