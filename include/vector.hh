#ifndef CONTAINERS_VECTOR_HH_
#define CONTAINERS_VECTOR_HH_

#include "internal/utils.hh"
#include "internal/vector_buf.hh"

namespace containers {

template <typename T>
class Vector : private internal::VectorBuf<T> {
 private:
  using internal::VectorBuf<T>::sz_;
  using internal::VectorBuf<T>::cap_;
  using internal::VectorBuf<T>::data_;

 public:
  Vector() noexcept {}
  explicit Vector(std::size_t sz) : internal::VectorBuf<T>(sz) {
    for (std::size_t i = 0; i < sz_; ++i) {
      internal::constructAt(data_ + i);
    }
  }
};

} // namespace containers

#endif // CONTAINERS_VECTOR_HH_
