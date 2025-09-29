#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_type(T value) {
  std::cout << "Integral type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print_type(T value) {
  std::cout << "Floating point type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_same<T, const char *>::value ||
                            std::is_same<T, char *>::value,
                        void>::type
print_type(T value) {
  std::cout << "C-Style string type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
print_type(T value) {
  std::cout << "String type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value &&
                        !std::is_same<T, const char *>::value &&
                        !std::is_same<T, char *>::value>::type
print_type(T value) {
  std::cout << "Ppinter type: " << *value << std::endl;
}

template <typename T>
typename std::enable_if<
    !std::is_integral<T>::value && !std::is_floating_point<T>::value &&
    !std::is_same<T, const char *>::value && !std::is_same<T, char *>::value &&
    !std::is_same<T, std::string>::value && !std::is_pointer<T>::value>::type
print_type(T value) {
  std::cout << "other type:" << value << std::endl;
}

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept FloatintPoint = std::is_floating_point_v<T>;

template <typename T>
concept Cstring = std::is_same_v<T, const char *> || std::is_same_v<T, char *>;

template <typename T>
concept Stdstring = std::is_same_v<T, std::string>;

template <typename T>
concept PointerType =
    std::is_pointer_v<T> && !std::is_same_v<T, const char *> &&
    !std::is_same_v<T, char *>;

void cout_type(Integral auto value) {
  std::cout << "Integral type: " << value << std::endl;
}
void cout_type(FloatintPoint auto value) {
  std::cout << "FloatintPoint type: " << value << std::endl;
}
void cout_type(Cstring auto value) {
  std::cout << "Cstring type: " << value << std::endl;
}
void cout_type(Stdstring auto value) {
  std::cout << "Stdstring type: " << value << std::endl;
}
void cout_type(PointerType auto value) {
  std::cout << "PointerType type: " << value << std::endl;
}

template <typename T>
  requires(!Integral<T> && !FloatintPoint<T> && !Cstring<T> && !Stdstring<T> &&
           !PointerType<T>)
void cout_type(T value) {
  std::cout << "other type: " << value << std::endl;
}
