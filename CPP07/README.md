# 🧠 42 Cursus - C++ Module 07

## 📌 Description

C++ Module 07 at School 42 explores the concept of **templates** in C++. This module introduces **function templates** and **class templates**, allowing you to write flexible, reusable, and type-agnostic code. You will also learn about **generic programming**, template instantiation, and template specialization.

---

## 🚀 Topics Covered

- **Function Templates**: Create reusable functions that operate on generic types.
- **Class Templates**: Build template-based data structures and utilities.
- **Template Instantiation**: Understand how templates are compiled and instantiated.
- **Template Specialization**: Provide specific behavior for certain types.
- **Generic Programming**: Write code that works with any type.
- **Compile-time Polymorphism**: Use templates to achieve polymorphism without virtual functions.

---

## 📁 Project Structure

The exercises in this module will generally follow this structure:

```
/Module_07
├── whatever.hpp
├── Array.hpp
├── main.cpp
└── Makefile
```

Compile with:

```bash
c++ -Wall -Wextra -Werror -std=c++98 <files>.cpp -o program
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `Start with a few functions`

Implement a template function `swap` that swaps two variables, `min` that returns the smaller of two values, and `max` that returns the larger. These functions should work with any comparable type. Test your implementation with multiple data types.

### 📌 Exercise 01 - `iter`

Create a function template `iter` that applies a given function to each element of an array. This will require using function pointers and templates. The function should be generic and work with any type.

### 📌 Exercise 02 - `Array`

Implement a class template `Array<T>` that mimics a basic fixed-size array with bounds checking. Include:
- Default constructor
- Constructor with size
- Copy constructor and assignment operator
- `operator[]` for element access
- Method to return array size
Make sure to handle memory management correctly and avoid leaks.

---

## ✅ Code Guidelines

- [ ] Templates must be defined in header files.
- [ ] Proper memory management in class templates.
- [ ] Use of const-correctness and references where needed.
- [ ] Code is clean, modular, and readable.
- [ ] Handle edge cases (e.g., out-of-bounds access).
- [ ] No warnings with `-Wall -Wextra -Werror`.

---

## 📚 Useful References

- [C++ Reference - Templates](https://en.cppreference.com/w/cpp/language/templates)
- [C++ Reference - Function Templates](https://en.cppreference.com/w/cpp/language/function_template)
- *Effective C++* by Scott Meyers
- *C++ Templates: The Complete Guide* by David Vandevoorde

---

## 🏁 Conclusion

Module 07 strengthens your C++ skills through the use of generic programming and templates. By learning how to write flexible and reusable code, I am better prepared to tackle real-world software challenges with elegance and efficiency.