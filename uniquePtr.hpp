#pragma once

template <typename T>
class unique_ptr {
    T* ptr_;

   public:
    unique_ptr() : ptr_(nullptr) {}
    explicit unique_ptr(T* ptr) : ptr_(ptr) {}

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& movingPtr) noexcept {
        ptr_ = movingPtr.ptr_;
        movingPtr.ptr_ = nullptr;
    }
    void operator=(unique_ptr&& movingPtr) noexcept {
        if (ptr_ != nullptr)
            delete ptr_;

        ptr_ = movingPtr.ptr_;
        movingPtr.ptr_ = nullptr;
    }

    ~unique_ptr() { delete ptr_; }

    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }

    T* get() const { return ptr_; }
    T* release() noexcept {
        T* ptr = nullptr;
        std::swap(ptr, ptr_);
        return ptr;
    }
    void swap(unique_ptr& ptr) noexcept {
        std::swap(ptr_, ptr.ptr_);
    }
    void reset() {
        T* ptr = release();
        delete ptr;
    }
};