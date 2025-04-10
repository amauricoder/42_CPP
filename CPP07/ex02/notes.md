# .tpp file

### **What does creating a `.tpp` file in C++98 mean, and what should go inside it?**

A file with the `.tpp` extension in C++ is usually used as a convention to hold template implementations. While it’s not an official standard in C++, this extension is a common practice in projects that use templates extensively. Here’s what you need to know:

---

### **Why use a `.tpp` file?**
In C++, template implementations need to be visible to the compiler at the time of instantiation, which typically means that both the definition and the implementation of a template must reside in the same header file (`.h` or `.hpp`). However, to better organize the code, many developers opt to separate the implementations into `.tpp` files.

This separation is done to:
- Improve code organization.
- Simplify maintenance, especially when templates have large implementations.
- Clearly differentiate between definitions (interfaces) and implementations.

---

### **What goes into a `.tpp` file?**
The `.tpp` file typically contains **the implementations of template functions or methods** that were declared in the corresponding header file.

#### Typical Structure:

1. **Header File (`.hpp`)**:
   Contains the definitions and declarations of the template.
   ```cpp
   // my_template.hpp
   #ifndef MY_TEMPLATE_HPP
   #define MY_TEMPLATE_HPP

   template <typename T>
   class MyTemplate {
   public:
       MyTemplate(T value);
       void display();
   private:
       T data;
   };

   #include "my_template.tpp" // Includes the implementation

   #endif // MY_TEMPLATE_HPP
   ```

2. **`.tpp` File**:
   Contains the implementations of the functions or methods.
   ```cpp
   // my_template.tpp
   #include <iostream>

   template <typename T>
   MyTemplate<T>::MyTemplate(T value) : data(value) {}

   template <typename T>
   void MyTemplate<T>::display() {
       std::cout << "Value: " << data << std::endl;
   }
   ```

---

### **Why does the compiler need this in C++98?**
In C++98 (and later versions), the compiler needs access to the complete source code of a template to generate the necessary instances since templates are resolved at compile time.

If you separated the implementation of a template into a regular `.cpp` file, the compiler would not be able to generate instances for different types because it wouldn’t have access to the implementation when compiling the code that uses the template.

---

### **How to use the `.tpp` file?**
To use the `.tpp` file, you explicitly **include it** at the end of the corresponding header file, as shown in the example above:
```cpp
#include "my_template.tpp"
```

This inclusion is necessary because the `.tpp` file must be included wherever the template is declared (usually in the `.hpp` file), as templates need to be fully defined to be used.

---

### **Conclusion**
The `.tpp` file is an organizational practice for implementing templates in C++, particularly useful in larger projects. It helps separate definitions from implementations, keeping the code cleaner and more readable, but it does not alter the fundamental behavior of the compiler.

