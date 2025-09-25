# C++ Module 06

[![en](https://img.shields.io/badge/lang-English-blue.svg)](README.md)
[![es](https://img.shields.io/badge/lang-Español-red.svg)](README.es.md)



## Exercise 00: ScalarConverter

### 📌 Summary
Implement a class **`ScalarConverter`** containing a single static method:

```cpp
static void convert(const std::string& literal);
```

The method receives a string representing a C++ literal and must convert it into the four basic scalar types:

* Char
* Int
* Float
* Double

The class **must not be instantiable** (constructors/destructors private or deleted).

---

### Exercise Objectives

1. Detect the actual type of the literal received as `std::string`.
2. Convert it into its base type (`char`, `int`, `float`, `double`).
3. Explicitly convert it into the remaining scalar types.
4. Display the result in a clear and precise format, as shown in the subject examples.
5. Handle special cases:

   * Pseudo-literals: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.
   * Out-of-range values (`int` overflow).
   * Non-displayable characters.

---

### Key Concepts

#### Type conversion in C++

* **Implicit cast**: the compiler automatically converts between compatible types (e.g., `int → double`).
* **Explicit cast**: the programmer forces the conversion using `static_cast`, `dynamic_cast`, `reinterpret_cast` or `const_cast`.
  For this exercise, only `static_cast` is needed.

Example:

```cpp
double d = 42.0;
int i = static_cast<int>(d);   // convert double → int
char c = static_cast<char>(i); // convert int → char
```

---

#### Literals in C++

* Char literal: `'a'`, `'Z'`.
* Int literal: `42`, `-7`.
* Float literal: `4.2f`, `-0.0f`. Always ending in `f`.
* Double literal: `4.2`, `-0.0`.
* Pseudo-literals: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.

---

#### Useful libraries

* `<string>`: string manipulation.
* `<iostream>`: input/output.
* `<limits>`: numeric ranges (`std::numeric_limits<int>::max()`).
* `<iomanip>`: formatting (`std::setprecision`).
* `<cmath>`: math functions (`std::isnan`, `std::isinf`).
* `<cctype>`: character checks (`std::isdigit`, `isprint`).

---

#### Type detection

The algorithm follows simple rules:

* Char: length 1 and not a digit.
* Int: only digits (optional `+` or `-`).
* Float: contains `.` and ends with `f` or is a pseudo-literal (`nanf`, `+inff`, `-inff`).
* Double: contains `.` and does not end with `f`, or is a pseudo-literal (`nan`, `+inf`, `-inf`).
* Other: unrecognized type → conversions impossible.

---

#### Exception handling

The value is stored as `double` to simplify conversions to other types.

* `std::stoi`, `std::stoll`, `std::stof`, `std::stod` may throw `std::out_of_range` or `std::invalid_argument`.
* Catching exceptions allows marking conversions as impossible without stopping execution.

---

## Exercise 01: Serialization

### 📌 Summary

Implement a class **`Serializer`** that cannot be instantiated and that provides two static methods:

```cpp
static uintptr_t serialize(Data* ptr);
static Data* deserialize(uintptr_t raw);
```

* `serialize`: converts a pointer (`Data*`) into an unsigned integer (`uintptr_t`).
* `deserialize`: converts that integer (`uintptr_t`) back into a pointer (`Data*`).

Additionally, a `Data` structure with some members must be defined, and a program must demonstrate that serializing and then deserializing returns the original pointer.

---

### Exercise Objectives

1. Practice pointer reinterpretation with `reinterpret_cast`.
2. Understand the use of `uintptr_t` for storing memory addresses.
3. Verify that a pointer can be “serialized” into an integer and then recovered correctly.
4. Use a structure with real data to validate the process.

---

### Key Concepts

#### What is `uintptr_t`?

It is an unsigned integer type defined in `<cstdint>`. It is guaranteed to be able to store a memory address without loss of information.

Example:

```cpp
int x = 10;
int* ptr = &x;
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
```

---

#### What is `reinterpret_cast`?

It is a C++ cast that allows converting between pointer types and integers.
It does not alter the value in memory, it simply **reinterprets the bits**.

