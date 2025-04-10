
# 🧠 42 Cursus - C++ Module 03

## 📌 Description

The C++ Module 03 introduces you to object-oriented programming (OOP) with a focus on class design, inheritance, polymorphism, and dynamic memory management. In this module, you'll work with the **ClapTrap** project, where you will implement classes that model robots and extend their functionalities.

---

## 🚀 Topics Covered

- **Classes and Objects**: Understanding class design, constructors, destructors, and member functions.
- **Encapsulation**: Using private, public, and protected members to control access.
- **Inheritance and Polymorphism**: Extending functionality and utilizing virtual functions.
- **Dynamic Memory Management**: Using `new`, `delete`, and smart pointers.
- **Operator Overloading**: Overloading operators for custom behavior in classes.
- **Memory Management**: Preventing memory leaks and managing dynamic allocation effectively.
- **Object-Oriented Programming**: Applying OOP principles like abstraction, encapsulation, and inheritance.

---

## 📁 Project Structure

The **ClapTrap** project contains a series of class implementations that are built on top of one another. You will work with multiple files for class definitions, implementations, and testing. Here's the general structure:

```
/ClapTrap
├── ClapTrap.hpp
├── ClapTrap.cpp
├── ScavTrap.hpp
├── ScavTrap.cpp
├── FragTrap.hpp
├── FragTrap.cpp
└── main.cpp
```

Each exercise is independent and can be compiled individually. To compile your code, use the following command:

```bash
c++ -Wall -Wextra -Werror <file>.cpp -o <executable>
```

---

## 🧪 Exercises

### 📌 Exercise 00 - `Aaaaand... OPEN!`

Implement a ClapTrap class with attributes like name, hit points, energy points, and attack damage. The class should include functions for attacking, taking damage, and repairing, with proper messaging for each action, and display constructor/destructor calls.

### 📌 Exercise 01 - `Serena, my love!`

Create a ScavTrap class derived from ClapTrap, inheriting its attributes and methods but overriding the constructor, destructor, and attack() function to print different messages. Additionally, implement a unique guardGate() function for the ScavTrap to display a message when it's in Gatekeeper mode, and ensure proper construction/destruction chaining in your tests.

### 📌 Exercise 02 - `Repetitive work`

Create a FragTrap class that inherits from ClapTrap, similar to ScavTrap, but with different constructor/destructor messages and attributes: 100 hit points, 100 energy points, and 30 attack damage. Implement a unique highFivesGuys() function to display a high-five request, and ensure proper construction/destruction chaining in your tests.

### 📌 Exercise 03 - `Now it’s weird!`

Create a DiamondTrap class that inherits from both FragTrap and ScavTrap, choosing attributes and methods from both parent classes. The class should have a private name attribute and a special whoAmI() function that displays both its name and the ClapTrap's name. Ensure proper handling of multiple inheritance and add tests for this complex behavior.


---

## 🛠️ Compilation

To compile each file, use the following command:

```bash
c++ -Wall -Wextra -Werror <file>.cpp -o <executable>
```

This will ensure that there are no warnings or errors in your code.

---

## ✅ Code Guidelines

- [ ] Code is clean, well-organized, and properly commented.
- [ ] No warnings when compiling with `-Wall -Wextra -Werror`.
- [ ] Proper implementation of constructors, destructors, and copy constructors.
- [ ] Use of `new` and `delete` for dynamic memory management where necessary.
- [ ] Proper use of private and public members, following encapsulation principles.
- [ ] Avoid memory leaks by correctly freeing allocated memory.
- [ ] Consistent naming conventions: `CamelCase` for class names, `snake_case` for functions/variables.
- [ ] Correct implementation of object-oriented principles (inheritance, encapsulation, abstraction).

---

## 📚 Useful References

- [C++ Reference - Classes](https://en.cppreference.com/w/cpp/language/classes)
- [C++ Reference - Memory Management](https://en.cppreference.com/w/cpp/memory)
- *Effective C++* by Scott Meyers
- *C++ Primer* by Stanley B. Lippman

---

## 🏁 Conclusion

Module 03 introduces advanced object-oriented programming concepts and extends your knowledge of C++ with practical examples like **ClapTrap**, **ScavTrap**, and **FragTrap**. By completing this module, I gained deeper insight into inheritance, polymorphism, and dynamic memory management.
