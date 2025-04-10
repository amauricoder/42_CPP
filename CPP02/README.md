# 42_CPP02
CPP 02 project repository of 42 Porto.

## Documentation and useful information about the project

This project is about Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form and Fixed Point numbers.

- Ad-hod polymorphism
Is a type of polymorphism in programmin that allow functions or operators to behave 
dufferentky based on their input types.
It is achieved by defining multiple implementations of a function or operator for different data types, enabling the same function name or symbol to perform distinct actions based on the context.

operator overloading.
    Type-specific Behavior:
        Ad-hoc polymorphism allows functions or operators to perform type-specific operations.
        For example, the + operator in many languages is overloaded to handle both numerical addition and string concatenation.

    Function Overloading:
        Ad-hoc polymorphism is often implemented through function overloading, where multiple functions with the same name are defined but differentiated by their parameter types or count.

    Operator Overloading:
        Many programming languages allow operators to be overloaded to provide customized behavior for user-defined types.

    Compile-time Resolution:
        The appropriate implementation of an overloaded function or operator is typically chosen at compile time based on the types of the arguments.

Orthodox Canonical
Its a design pattern convention, where 
every class needs to have a default constructor, copy constructor,
copy assignment operator,
and the destructor.
What is the point of it?
The term Orthodox Canonical refers to the set of special functions (constructor, destructor, copy constructor, copy assignment operator) that must be implemented correctly to ensure that the class follows best practices in resource management and proper object behavior.

copy constructor creates a new object as a copy of another object.
copy assignment operator gives the content of an object to another, even after they
are already initialized.

