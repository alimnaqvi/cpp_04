# C++ Module 03: Polymorphism, Abstract Classes, and Interfaces

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This project is part of the C++ modules at 42 School.

This module explores fundamental concepts of Object-Oriented Programming in C++, focusing on inheritance, subtype polymorphism, abstract classes, and interfaces. Through a series of exercises, we implement these concepts to understand their practical applications and importance in C++ development, particularly concerning memory management and class design.

## Core Concepts Covered

*   **Subtype Polymorphism:** Achieved through inheritance and virtual functions, allowing objects of derived classes to be treated as objects of a base class type.
*   **Virtual Functions:** Enabling dynamic dispatch, where the function called through a base class pointer/reference is determined at runtime based on the object's actual type.
*   **Virtual Destructors:** Ensuring correct cleanup when deleting derived objects through base class pointers.
*   **Abstract Base Classes (ABCs):** Classes with one or more pure virtual functions, designed to be base classes and cannot be instantiated directly. They define an interface that derived classes must implement.
*   **Pure Virtual Functions:** Functions declared with `= 0`, making the class abstract and forcing derived classes to provide an implementation.
*   **Interfaces:** Typically implemented as abstract classes with *only* pure virtual functions, defining a contract without providing any implementation.
*   **Deep Copy vs. Shallow Copy:** Understanding the difference and implementing deep copies (Rule of Three/Five) when classes manage dynamic memory to avoid issues like double-freeing or dangling pointers.
*   **Dynamic Memory Management:** Using `new` and `delete` within classes and ensuring proper resource management (RAII principles).
*   **Orthodox Canonical Form (OCF) / Rule of Three/Five:** Implementing destructors, copy constructors, and copy assignment operators correctly, especially when dynamic memory is involved.

---

## Exercise Breakdown

### Exercise 00: Polymorphism

*   **Task Description:**
    *   Introduce the concept of polymorphism using virtual functions.
    *   Create a small hierarchy of classes (`Animal`, `Dog`, `Cat`).
    *   Demonstrate that calling a `virtual` member function via a base class pointer executes the derived class's version.
    *   Highlight the difference in behavior when the function is *not* virtual (`WrongAnimal`, `WrongCat`).
    *   Implement virtual destructors to ensure proper cleanup in polymorphic scenarios.

*   **Implementation Details:**
    *   `Animal` class serves as the base with a `type` attribute and a `virtual` function `makeSound()` and a `virtual ~Animal()` destructor.
    *   `Dog` and `Cat` classes inherit from `Animal` and `override` the `makeSound()` function to provide specific sounds ("Woof!", "Meow!"). Their destructors also use `override`.
    *   `WrongAnimal` and `WrongCat` classes mirror the structure but `WrongAnimal::makeSound()` is *not* virtual, demonstrating static dispatch (the base version is always called via a base pointer).
    *   The `main` function instantiates derived classes using base class pointers (`Animal* meta = new Dog();`) and calls `makeSound()` to show polymorphic behavior for `Animal` and lack thereof for `WrongAnimal`.

*   **Key Concepts Learned:**
    *   `virtual` keyword for functions and destructors.
    *   Function `override` keyword (C++11 and later) for clarity and safety.
    *   Dynamic Dispatch (Runtime Polymorphism).
    *   Static Dispatch (Compile-time Polymorphism).
    *   Importance of `virtual` destructors when deleting derived objects via base pointers to prevent memory leaks and undefined behavior.

### Exercise 01: I don’t want to set the world on fire (Deep Copy)

*   **Task Description:**
    *   Introduce dynamic memory allocation within class members.
    *   Address the problems arising from default shallow copies when dynamic memory is involved.
    *   Implement deep copying semantics using the Rule of Three (or Five).
    *   Ensure no memory leaks occur during object copying, assignment, or destruction.

*   **Implementation Details:**
    *   A `Brain` class is created, holding an array of `std::string` ideas. It manages its own resources and follows the OCF.
    *   `Dog` and `Cat` classes are modified to contain a pointer (`Brain* mBrain`) initialized with `new Brain()` in their constructors.
    *   **Deep Copy Implementation:**
        *   **Destructor (`~Dog()`, `~Cat()`):** Must `delete mBrain`.
        *   **Copy Constructor (`Dog(const Dog&)`, `Cat(const Cat&)`):** Must allocate a *new* `Brain` and copy the contents from the source object's `Brain` (`mBrain = new Brain(*(other.mBrain));`).
        *   **Copy Assignment Operator (`operator=`):** Must handle self-assignment, `delete` the existing `mBrain`, allocate a *new* `Brain`, and copy the contents from the source object's `Brain`.
    *   The `main` function tests deep copying by creating copies and assigning objects, then modifying/destroying the original to ensure the copy remains valid (doesn't crash due to dangling pointers or double-free). An array of `Animal*` is used to test polymorphic behavior with the new `Brain` member.

*   **Key Concepts Learned:**
    *   Dynamic memory allocation (`new`, `delete`) within class members.
    *   Shallow Copy (default behavior for pointers - copies the address, not the data).
    *   Deep Copy (allocating new resources and copying the data).
    *   Rule of Three/Five (Destructor, Copy Constructor, Copy Assignment Operator).
    *   Memory leak prevention and avoiding double-free errors.
    *   Pointer management and ownership.

### Exercise 02: Abstract class

*   **Task Description:**
    *   Introduce abstract base classes (ABCs).
    *   Prevent the instantiation of a base class while allowing it to define a common interface for its derived classes.
    *   Ensure derived classes implement the interface defined by the ABC.

*   **Implementation Details:**
    *   The `Animal` class is made abstract by declaring at least one pure virtual function. In this case, `makeSound()` and `getFirstThought()` are declared as pure virtual:
        ```cpp
        virtual void makeSound() const = 0;
        virtual const std::string getFirstThought() const = 0;
        ```
    *   Attempting to instantiate `Animal` directly (e.g., `Animal myAnimal;`) will now result in a compile-time error.
    *   `Dog` and `Cat` classes *must* provide concrete implementations for `makeSound()` and `getFirstThought()` to be instantiable.
    *   The rest of the functionality (polymorphism, deep copy) remains the same, but now operates on a hierarchy rooted in an abstract class.

*   **Key Concepts Learned:**
    *   Abstract Base Class (ABC).
    *   Pure Virtual Functions (`virtual ... = 0;`).
    *   Compile-time prevention of instantiation for abstract classes.
    *   Enforcing interface implementation in derived classes.

### Exercise 03: Interface & recap

*   **Task Description:**
    *   Introduce the concept of interfaces using abstract classes with only pure virtual functions.
    *   Design and implement a system involving multiple interacting classes adhering to specific interfaces (`ICharacter`, `IMateriaSource`).
    *   Implement the `clone()` pattern for polymorphic copying.
    *   Manage memory carefully, especially concerning object ownership when objects are created, passed around, equipped, and unequipped.
    *   Handle potential circular dependencies between header files.

*   **Implementation Details:**
    *   **Interfaces:** `ICharacter` and `IMateriaSource` are defined with pure virtual functions (`getName`, `equip`, `unequip`, `use` for `ICharacter`; `learnMateria`, `createMateria` for `IMateriaSource`) and virtual destructors.
    *   **Abstract Class:** `AMateria` serves as an abstract base for materia types (`Ice`, `Cure`). It has a type, a `virtual void use(ICharacter& target)` function, and a `virtual AMateria* clone() const = 0` pure virtual function.
    *   **Concrete Classes:**
        *   `Ice` and `Cure` inherit from `AMateria`, providing implementations for `clone()` (returning a `new` instance of themselves) and `use()`.
        *   `Character` implements `ICharacter`, managing an inventory (`AMateria* mInventory[4]`). It handles deep copying of the inventory (using `clone()`) in its copy constructor and assignment operator, and deletes materia in its destructor. It includes logic for equipping, unequipping, and using materia.
        *   `MateriaSource` implements `IMateriaSource`, managing a template array (`AMateria* mLearnedMateria[4]`) of known materia. It uses `clone()` to create new materia instances in `createMateria`. It also handles deep copy and destruction of its learned materia.
    *   **Memory Management:** `main.cpp` includes careful handling of `AMateria` pointers. Unequipped materia or materia created but not learned/equipped are tracked (e.g., via a helper array `unequippedMateria`) to ensure they are deleted, preventing leaks. Deep copy operations are tested thoroughly.
    *   **Circular Dependencies:** Forward declarations (e.g., `class AMateria;` in `ICharacter.h`, `class ICharacter;` in `AMateria.h`) are used to break potential include cycles.

*   **Key Concepts Learned:**
    *   Interface design using abstract classes.
    *   `clone()` pattern for creating copies of objects polymorphically.
    *   Complex memory management and object ownership rules in a multi-class system.
    *   Handling circular dependencies with forward declarations.
    *   Rigorous testing of interactions, boundary conditions, and memory management.
    *   Reinforcement of OCF, polymorphism, and abstract classes.

---

## How to Compile and Run

Each exercise typically resides in its own directory (e.g., `ex00/`, `ex01/`, etc.). Navigate to the specific exercise directory in your terminal.

1.  **Compile:**
    ```bash
    make
    ```
    This will use the `Makefile` provided in the directory to compile the source files and create an executable (e.g., `polymorphism`, `deepCopy`, `abstractClass`, `interface`).

2.  **Run:**
    ```bash
    ./<executable_name>
    ```
    (Replace `<executable_name>` with the actual name specified in the `Makefile`, e.g., `./polymorphism`).

3.  **Clean:**
    *   To remove object files (`.o`):
        ```bash
        make clean
        ```
    *   To remove object files and the executable:
        ```bash
        make fclean
        ```

4.  **Re-compile:**
    *   To clean and rebuild everything:
        ```bash
        make re
        ```

---
