# 🧠 42 Cursus - C++ Module 05

## 📌 Description

C++ Module 05 at School 42 focuses on **operator overloading**, **exception handling**, and **class design for better object usability**. Through this module, you will practice implementing custom behavior for operators, explore proper use of exceptions, and build classes that integrate seamlessly into standard C++ idioms.

---

## 🚀 Topics Covered

- **Operator Overloading**: Implement custom behavior for comparison, assignment, and arithmetic operators.
- **Exception Handling**: Use `try`, `catch`, and `throw` to manage errors and ensure program robustness.
- **Custom Exceptions**: Create and use your own exception classes.
- **Encapsulation & Modularity**: Keep class implementations clean, intuitive, and safe.
- **Canonical Form**: Understand and apply the Orthodox Canonical Form (constructor, copy constructor, destructor, and assignment operator).

---

## 📁 Project Structure

Each exercise is self-contained and can be compiled individually. The project structure might look like:

```
/Module_05
├── Bureaucrat.hpp
├── Bureaucrat.cpp
├── main.cpp
└── Makefile
```

Compile using:

```bash
c++ -Wall -Wextra -Werror <file>.cpp -o <executable>
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `Mommy, when I grow
up, I want to be a bureaucrat!`

Create a class `Bureaucrat` with a name and a grade (int). The grade must be between 1 (highest) and 150 (lowest). Implement boundary checks and throw exceptions (`GradeTooHighException`, `GradeTooLowException`) when invalid values are set. Overload the `<<` operator to print a `Bureaucrat`.

### 📌 Exercise 01 - `Form up, maggots!`

Implement a `Form` class which has a name, a grade required to sign, and a grade required to execute. Only `Bureaucrats` of appropriate grade can sign it. Attempting to sign with a low-grade bureaucrat must throw a `GradeTooLowException`. Maintain integrity of const attributes and use exception-safe coding.

### 📌 Exercise 02 - `No, you need form 28B, not 28C...`

Make `Bureaucrat` and `Form` interact. A `Bureaucrat` should attempt to sign a `Form`, and you should handle this process using exceptions and informative output. Add methods to both classes to complete this flow, maintaining encapsulation and robust error handling.

### 📌 Exercise 03 - `At least this beats coffee-making`

Implement an Intern class with a makeForm() method that creates specific Form objects based on a string name and target, printing a creation message. Avoid using messy if/else chains—use clean, scalable logic to handle form selection and error reporting.

---

## ✅ Code Guidelines

- [ ] No memory leaks.
- [ ] Use of Orthodox Canonical Form.
- [ ] Proper exception classes and meaningful error messages.
- [ ] Use constant references where applicable.
- [ ] Avoid redundant code and ensure proper encapsulation.
- [ ] Clear and consistent formatting, naming, and documentation.

---

## 📚 Useful References

- [C++ Reference - Operator Overloading](https://en.cppreference.com/w/cpp/language/operators)
- [C++ Reference - Exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- *Effective C++* by Scott Meyers
- *C++ Primer* by Stanley B. Lippman

---

## 🏁 Conclusion

Module 05 teaches essential practices for writing idiomatic and safe C++ code using operator overloading and exception handling. Mastering these concepts will help the understanding of how high-level features in C++ integrate with object-oriented design.