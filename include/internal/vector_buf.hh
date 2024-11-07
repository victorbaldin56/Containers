#ifndef CONTAINERS_INTERNAL_VECTOR_BUF_HH_
#define CONTAINERS_INTERNAL_VECTOR_BUF_HH_

#include <algorithm>
#include <cstdlib>

namespace containers {

namespace internal {

template <typename T>
class VectorBuf {
 protected:
  std::size_t sz_ = 0;
  std::size_t cap_ = 0;
  T* data_ = nullptr;

 protected:
  VectorBuf() noexcept {}
  explicit VectorBuf(std::size_t sz)
      : sz_(sz),
        cap_(sz),
        data_(sz ? static_cast<T*>(::operator new(sz * sizeof(*data_)))
                 : nullptr) {}

  VectorBuf(const VectorBuf& other) = delete;
  VectorBuf& operator=(const VectorBuf& other) = delete;

  VectorBuf(VectorBuf&& other) noexcept
      : data_(other.data_), sz_(other.sz_), cap_(other.cap_) {
    other.data_ = nullptr;
    other.sz_ = 0;
    other.cap_ = 0;
  }

  VectorBuf& operator=(VectorBuf&& other) {
    std::swap(data_, other.data_);
    std::swap(sz_, other.sz_);
    std::swap(cap_, other.cap_);
    return *this;
  }
};

}

}

#endif // CONTAINERS_INTERNAL_VECTOR_BUF_HH_
