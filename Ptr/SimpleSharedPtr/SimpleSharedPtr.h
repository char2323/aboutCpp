#pragma once

struct ControlBlock {
  int ref_count;
  ControlBlock() : ref_count(1) {}
};

template <typename T> class SimpleSharePtr {
private:
  T *ptr;
  ControlBlock *control;
  void release() {
    if (control) {
      --control->ref_count;
      if (control->ref_count == 0) {
        delete ptr;
        ptr = nullptr;
        delete control;
        control = nullptr;
      }
    }
  }

public:
  SimpleSharePtr() : ptr(nullptr), control(nullptr) {}
  // SimpleSharePtr p(new Student());
  explicit SimpleSharePtr(T *p) : ptr(p) {
    if (p) {
      control = new ControlBlock();
    } else {
      control = nullptr;
    }
  }
  ~SimpleSharePtr() {
    if (ptr) {
      release();
    }
  }
  // s1;SimpleSharePtr s2(s1);
  SimpleSharePtr(const SimpleSharePtr &s) : ptr(s.ptr), control(s.control) {
    if (ptr) {
      ++control->ref_count;
    }
  }
  // SimpleSharePtr s2(new Student()); s2=s1;
  SimpleSharePtr &operator=(const SimpleSharePtr &s) {
    if (this != &s) {
      release();
      ptr = s.ptr;
      control = s.control;
      if (control) {
        control->ref_count++;
      }
    }
    return *this;
  }
  // SimpleSharePtr s2(std::move(s1));
  SimpleSharePtr(SimpleSharePtr &&s) noexcept : ptr(s.ptr), control(s.control) {
    s.ptr = nullptr;
    s.control = nullptr;
  }
  // SimpleSharePtr s2;s2=std::move(s1);
  SimpleSharePtr &operator=(SimpleSharePtr &&s) noexcept {
    if (this != &s) {
      release();
      ptr = s.ptr;
      control = s.control;
      s.control = nullptr;
      s.ptr = nullptr;
    }
    return *this;
  }

  // SimpleSharePtr s2(new Student()); s2->name="Charmmy";---->
  // s2.ptr->name="Charmmy";
  T *operator->() const { return ptr; }

  // SimpleSharePtr s2(new Student()); (*s2).name="Charmmy";
  // (*s2.ptr).name="Charmmy";
  T &operator*() const { return *ptr; }

  T *get() const { return ptr; }

  int use_count() const { return control ? control->ref_count : 0; }

  void reset(T *p = nullptr) {
    release();
    ptr = p;
    if (p) {
      control = new ControlBlock();
    } else {
      control = nullptr;
    }
  }
};
