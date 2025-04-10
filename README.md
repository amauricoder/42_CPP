# 🧠 42 Cursus - C++ Module 06

## 📌 Description

C++ Module 06 at School 42 introduces **type conversion**, **dynamic casting**, and the use of **runtime type identification (RTTI)** in polymorphic class hierarchies. This module is an essential step toward mastering safe downcasting and understanding the internal type mechanics of C++.

---

## 🚀 Topics Covered

- **Static and Dynamic Casts**: Learn when and how to use `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`.
- **RTTI (Run-Time Type Information)**: Use `typeid` and `dynamic_cast` to identify object types at runtime.
- **Safe Downcasting**: Use base class pointers to call derived class methods safely.
- **Polymorphism**: Rely on `virtual` functions to ensure correct object behavior.
- **Abstract Base Classes**: Utilize interfaces and pure virtual methods to enable polymorphic behavior.

---

Compile with:

```bash
c++ -Wall -Wextra -Werror -std=c++98 <files>.cpp -o identify
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `Conversion of scalar types`

Create a non-instantiable ScalarConverter class with a static convert() method that takes a string literal and prints its representation as char, int, float, and double. Handle special cases like non-displayable chars and pseudo-literals (nan, inf, etc.) appropriately.

### 📌 Exercise 01 - `Serialization`

Create a non-instantiable Serializer class with two static methods: serialize() to convert a Data* to a uintptr_t, and deserialize() to convert it back. Test by verifying that deserializing a serialized pointer returns the original Data object.

### 📌 Exercise 01 - `Identify real type`

Create a Base class with a virtual destructor and three derived classes A, B, and C. Implement generate() to randomly return a Base* to one of them, and use overloaded identify() functions (one with pointer, one with reference) to detect and print the actual type—without using typeid or <typeinfo>.

---

## ✅ Code Guidelines

- [ ] No memory leaks.
- [ ] Use of polymorphism and virtual destructors.
- [ ] Proper use of casting (avoid unsafe casts).
- [ ] Clean code with consistent naming.
- [ ] Proper handling of exceptions during dynamic casting.

---

## 📚 Useful References

- [C++ Reference - Casting Operators](https://en.cppreference.com/w/cpp/language/explicit_cast)
- [C++ Reference - typeid](https://en.cppreference.com/w/cpp/language/typeid)
- [C++ Reference - dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- *Effective C++* by Scott Meyers

---

## 🏁 Conclusion

Module 06 helps you master RTTI and safe type conversion techniques in C++. These tools are essential when working with polymorphic class hierarchies, ensuring that your casts and type checks are safe, meaningful, and efficient.