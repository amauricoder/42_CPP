# 🧠 42 Cursus - C++ Module 08

## 📌 Description

C++ Module 08 at School 42 focuses on **standard containers**, **iterators**, and **generic programming** using the C++ Standard Template Library (STL). This module helps you develop an understanding of efficient data storage, iteration, and STL algorithms in real-world programming.

---

## 🚀 Topics Covered

- **STL Containers**: Understand and use standard containers like `vector`, `list`, and `deque`.
- **Iterators**: Learn how iterators work and how to use them for container traversal.
- **Algorithms**: Apply STL algorithms like `find`, `sort`, `copy`, and others.
- **Generic Programming**: Write container-agnostic code with templates and iterators.
- **Functors**: Understand function objects and use them with algorithms.
- **Efficiency and Complexity**: Be aware of the time/space complexity of container operations.

---

## 📁 Project Structure

Each exercise builds on STL knowledge with a focus on different containers and patterns. A typical structure might be:

```
/Module_08
├── easyfind.hpp
├── Span.hpp
├── MutantStack.hpp
├── main.cpp
└── Makefile
```

Compile using:

```bash
c++ -Wall -Wextra -Werror -std=c++98 <files>.cpp -o stl_program
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `easyfind`

Write a function template `easyfind` that searches for an integer in any container supporting iterators. Return the iterator if found, otherwise throw an exception. Test it on multiple containers (`vector`, `list`, etc.).

### 📌 Exercise 01 - `Span`

Implement a class `Span` that stores a collection of integers and can compute the shortest and longest span (i.e., difference) between any two elements. Handle exceptions when the span can't be calculated (e.g., insufficient elements).

### 📌 Exercise 02 - `Mutated abomination`

Create a class `MutantStack` that inherits from `std::stack` and adds iterator support. This enables iteration through stack elements like a container. Implement custom begin/end methods using `std::stack::container_type`.

---

## ✅ Code Guidelines

- [ ] Use STL containers and algorithms where appropriate.
- [ ] Proper error handling and exceptions.
- [ ] Templates should support multiple container types when applicable.
- [ ] Code should be clean, readable, and modular.
- [ ] No memory leaks, no warnings with `-Wall -Wextra -Werror`.

---

## 📚 Useful References

- [C++ Reference - STL Containers](https://en.cppreference.com/w/cpp/container)
- [C++ Reference - Algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [C++ Reference - Iterators](https://en.cppreference.com/w/cpp/iterator)
- *Effective STL* by Scott Meyers

---

## 🏁 Conclusion

Module 08 equiped me with practical skills to write efficient, generic code using the STL. Mastery of containers, iterators, and algorithms is essential for modern C++ development, and this module provides a solid foundation to build upon.