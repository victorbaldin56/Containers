#ifndef CONTAINERS_INTERNAL_UTILS_HH_
#define CONTAINERS_INTERNAL_UTILS_HH_

#include <utility>

namespace containers {

namespace internal {

template <typename T>
void constructAt(T* p, const T& rhs) { new (p) T(rhs); }

template <typename T>
void constructAt(T* p, T&& rhs = T()) { new (p) T(std::move(rhs)); }

template <class T>
void destroy(T* p) { p->~T(); }

}

}

#endif // CONTAINERS_INTERNAL_UTILS_HH_
