# 🧠 42 Cursus - C++ Module 09

## 📌 Description

C++ Module 09 at School 42 focuses on **sequence containers**, **template specialization**, and **performance-oriented programming** using standard containers like `list` and `deque`. The module emphasizes parsing, sorting, and evaluating performance between different container types.

---

## 🚀 Topics Covered

- **Container Comparison**: Understanding the differences between `std::list` and `std::deque`.
- **Parsing Inputs**: Safely parse and validate command-line arguments.
- **Template Programming**: Create container-agnostic functions and classes.
- **Performance Measurement**: Use timing utilities to evaluate algorithm efficiency.
- **Sorting Algorithms**: Implement efficient sorting techniques on different containers.
- **STL Integration**: Practice STL usage in realistic applications.

---

## 📁 Project Structure

The main project involves creating a sorting utility for sequences using multiple container types:

```
/Module_09
├── PmergeMe.hpp
├── PmergeMe.cpp
├── main.cpp
└── Makefile
```

Compile using:

```bash
make 
```

---

## 🧪 Exercise 00- `Bitcoin Exchange`

Create a program `btc` that reads a file of dates and values, multiplies each value by the closest (lower or equal) bitcoin price from a CSV database, and prints the result. Used a `std::map` to store and efficiently retrieve bitcoin prices by date, handling invalid inputs, formatting errors, and edge cases with appropriate messages.

## 🧪 Exercise 01 - `Reverse Polish Notation`

Create a program RPN that takes a Reverse Polish Notation expression as input, processes it using a std::stack to evaluate the result, and prints the final value. Operands (0–9) and operators (+, -, *, /) are pushed and processed using stack logic; errors like invalid input or malformed expressions are reported via standard error.


## 🧪 Exercise 02 - `PmergeMe`

Create a program `PmergeMe` that takes a sequence of positive integers as input (via command-line arguments), parses them, and sorts them using both `std::deque` and `std::list`.

### Key Features:
- Validate inputs (positive integers only).
- Store data in both `std::deque` and `std::list`.
- Sort both containers using a custom merge-insert algorithm.
- Measure and print the time taken by each container to perform the sort.
- Compare the results and performance between the two.

---

## ✅ Code Guidelines

- [ ] Follow the Orthodox Canonical Form when applicable.
- [ ] No memory leaks or undefined behavior.
- [ ] Proper error messages for invalid input.
- [ ] Efficient parsing and sorting implementations.
- [ ] Use const references and avoid unnecessary copies.
- [ ] Compare performance results clearly and accurately.

---

## 📚 Useful References

- [C++ Reference - list](https://en.cppreference.com/w/cpp/container/list)
- [C++ Reference - deque](https://en.cppreference.com/w/cpp/container/deque)
- [C++ Reference - chrono](https://en.cppreference.com/w/cpp/chrono)
- [Merge-Insertion Sort](https://en.wikipedia.org/wiki/Merge-insertion_sort)

---

## 🏁 Conclusion

Module 09 brings together your C++ skills to solve a performance-sensitive problem with STL containers and algorithms. Understanding how different containers behave under the same operations is crucial for writing optimized and scalable applications.
