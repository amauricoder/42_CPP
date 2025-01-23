## What are template functions?
- They allow us to create generic functions that can work with different types of data without the need of overload the function from any kind. They are widely used to avoid code repetition.
Basic syntax:

```C++
template <typename T> <br>
	T myFunction(T a, T b)
{
	return a > b ? a : b;
}
```

- template \<typename T>

	Declares a paramether of generic type T.
	We can use other names like class T (they are the same on template context).

- T

	This represents a generic type. It will be replaced during compilation.

### Details

If necessary, you can specify explicitly the type of the function
``` C++
std::cout << max<int>(10,12) \>>
```

### Benefits

- Code reutilization: Unic implementation for a lot of types.
- Flexibility: any kind is compatible.

### limitations (C++98)

- Templates can only be used with types that are supported by the operations used on the body of the function.

- It doesn't support directly generic functions with different types (ex: T and U), but the can work with addicional templaes.

## Must be declared on header files

- In C++, template definitions must be available wherever they are instantiated, meaning the compiler needs access to the full implementation of a template to generate the code for each specific type. This is why templates are usually defined in header files, rather than separated into a .cpp file like normal functions or classes.

Steps to Define Templates in Header Files:
1. Define the Template in the Header File

    Include both the declaration and implementation in the header file.
    This ensures that any file including the header can instantiate the template with any type.

**Why Templates Must Be Defined in Header Files**

Templates are instantiated at compile-time for specific types, so the compiler needs to see the full definition when it generates code. If only the declaration is available in the header, and the implementation is in a .cpp file, the compiler will not have enough information to generate the required code for the template instantiation. This will result in linker errors.

By defining templates directly in the header file (or including their implementation via a secondary header), you ensure that the compiler has access to everything it needs during compilation.


