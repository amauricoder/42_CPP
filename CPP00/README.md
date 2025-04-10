# 🧠 42 Cursus - C++ Module 00

## 📌 Description

This is the first module in the 42 C++ curriculum. It introduces the basics of C++ and serves as a bridge between C and C++. The goal is to get familiar with C++ syntax, I/O handling, functions, and object-oriented concepts like classes and encapsulation.

---

## 🚀 Topics Covered

- Differences between C and C++
- Basic syntax and structure of C++
- Input and output with `std::cin` and `std::cout`
- Primitive types and variables
- Functions and scope
- String manipulation
- Static functions and variables
- Introduction to classes and encapsulation

---

## 📁 Project Structure

Each exercise is located in its own directory and contains one or more `.cpp` files. All exercises are independent of each other and should be compiled separately using:

```bash
c++ -Wall -Wextra -Werror <file>.cpp -o <executable>
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `megaphone`

Write a simple program that takes arguments from the command line and prints them in uppercase. If no arguments are given, it prints a default loud noise message.

### 📌 Exercise 01 - `PhoneBook`

Implement a simple phonebook using a class. This exercise introduces class structure, private attributes, and public methods. You will work with:

- Class definition and instantiation
- User input
- Fixed-size storage
- Text formatting and truncation for table-like output

### 📌 Exercise 02 - `String and Streams`

Practice manipulating strings using `std::string`, `std::getline`, and `std::stringstream`. You'll handle input parsing, formatting, and conversion of types using streams.

### 📌 Exercise 03 - `Namespaces and Scope`

This task focuses on understanding variable scope and the use of `namespace`, `static` variables, and their lifetime within the application.

### 📌 Exercise 04 - `Functions and References`

Understand how references work in C++ and how to pass variables by reference to functions. You'll learn the differences between value and reference semantics, and how they affect behavior and performance.

---

## 🛠️ Compilation

All exercises should be compiled using the following flags to enforce strict coding practices:

```bash
c++ -Wall -Wextra -Werror <file>.cpp -o <executable>
```

---

## ✅ Code Guidelines

- [ ] Code is clean, well-organized, and properly commented
- [ ] No warnings when compiling with `-Wall -Wextra -Werror`
- [ ] Proper usage of `std::string` and input/output streams
- [ ] CamelCase for class names, snake_case for variables and functions
- [ ] Clear separation of concerns and modular design
- [ ] Naming conventions align with 42 standards

---

## 📚 Useful References

- [cplusplus.com - std::string](https://cplusplus.com/reference/string/string/)
- [cppreference.com](https://en.cppreference.com/)
- *A Tour of C++* by Bjarne Stroustrup
- *C++ Primer* by Stanley B. Lippman

---

## 🏁 Conclusion

Even though Module 00 may seem simple, it builds a strong foundation for the rest of the C++ modules. Pay close attention to best practices, especially regarding input/output, code organization, and class structure.

Good luck and happy coding! 🚀