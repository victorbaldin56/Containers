#ifndef CONTAINERS_VECTOR_HH_
#define CONTAINERS_VECTOR_HH_

#include "internal/utils.hh"
#include "internal/vector_buf.hh"

namespace containers {

// provides Vector interface
template <typename T>
class Vector : private internal::VectorBuf<T> {
 private:
  using internal::VectorBuf<T>::sz_;
  using internal::VectorBuf<T>::cap_;
  using internal::VectorBuf<T>::data_;

 public:
  Vector() noexcept {}
  explicit Vector(std::size_t sz) : internal::VectorBuf<T>(sz) {}

  Vector(const Vector& rhs) : internal::VectorBuf<T>(rhs.sz_) {
    std::copy(rhs.data_, rhs.data_ + rhs.sz_, data_);
  }

  Vector& operator=(const Vector& rhs) {
    Vector tmp(rhs);
    std::swap(tmp, *this);
    return *this;
  }

  Vector(Vector&& rhs) = default;
  Vector& operator=(Vector&& rhs) = default;

 public:
  T& operator[](std::size_t pos) noexcept { return data_[pos]; }
  const T& operator[](std::size_t pos) const noexcept { return data_[pos]; }

  T& front() noexcept { return data_[0]; }
  const T& front() const noexcept { return data_[0]; }

  T& back() noexcept { return data_[sz_ - 1]; }
  const T& back() const noexcept { return data_[sz_ - 1]; }

  T* data() noexcept { return data_; }
  const T* data() const noexcept { return data_; };

 public:
  bool empty() const noexcept { return sz_; }
  std::size_t size() const noexcept { return sz_; }
  std::size_t capacity() const noexcept { return cap_; }

  void reserve(std::size_t new_cap) {
    if (new_cap <= cap_) {
      return;
    }

    internal::VectorBuf<T> tmp(new_cap);
  }
};

} // namespace containers

#endif // CONTAINERS_VECTOR_HH_
