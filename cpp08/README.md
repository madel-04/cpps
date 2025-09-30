# C++ Module 08 – STL Containers and Algorithms

This module introduces the **Standard Template Library (STL)** in C++98.  
The goal is to **use containers and algorithms instead of reinventing the wheel**.  
Each exercise focuses on a different aspect of STL containers, algorithms, and iterators.

---

## 📌 Exercise 00 – `easyfind`

### Goal
Implement a **function template** `easyfind` that:
- Accepts a container of integers (e.g., `std::vector<int>`, `std::list<int>`).
- Accepts an integer to search for.
- Finds the first occurrence of the integer in the container.

### Theory
- **Algorithms in `<algorithm>`**  
  - `std::find(first, last, value)` → searches a range `[first, last)` for a value.
  - Returns an iterator to the element if found, otherwise returns `last`.
- **Iterators**  
  - Abstract pointers that allow traversal of STL containers.
  - Each container defines its own iterator types (`iterator`, `const_iterator`).
- **Exceptions**  
  - If the element is not found, `easyfind` should throw an exception (`std::runtime_error`).

### Key Concepts
- Function templates allow generic programming.
- Iterators make algorithms independent of container type.
- Exceptions provide a clean way to handle “not found” cases.

---

## 📌 Exercise 01 – `Span`

### Goal
Implement a class `Span` that:
- Stores up to **N integers** (N fixed at construction).
- Supports adding numbers (`addNumber`) or a range of numbers (`addNumbers`).
- Computes:
  - `shortestSpan()` → the minimum difference between any two numbers.
  - `longestSpan()` → the maximum difference between any two numbers.

### Theory
- **Vector vs Multiset**
  - `std::vector` is dynamic but unordered → requires sorting (`O(n log n)`) each time `shortestSpan()` is called.
  - `std::multiset` is always sorted internally → insertion costs `O(log n)` but `shortestSpan()` is faster (`O(n)` without sorting).
- **Algorithms in `<algorithm>`**
  - `std::sort` → sorts a sequence.
  - `std::min_element` and `std::max_element` → find minimum and maximum values.
- **Iterators**
  - Used to traverse containers and insert ranges (`addNumbers` with `[begin, end)`).
- **Exceptions**
  - Adding beyond capacity or calling spans with fewer than 2 numbers must throw.

### Key Concepts
- Trade-off: `vector` is efficient for insertion but costly for span queries.  
- `multiset` is slower for insertion but efficient for frequent span queries.  
- Always think about algorithmic complexity:  
  - `vector` → `addNumber = O(1)`, `shortestSpan = O(n log n)`  
  - `multiset` → `addNumber = O(log n)`, `shortestSpan = O(n)`  

---

## 📌 Exercise 02 – `MutantStack`

### Goal
Implement a `MutantStack` class that:
- Behaves like a standard `std::stack`.
- Provides **iterators**, which `std::stack` does not.

### Theory
- **Container Adapters**
  - `std::stack` is not a container but an **adapter** that wraps another container (default: `std::deque`).
  - It provides restricted access (`push`, `pop`, `top`, `size`) but hides iterators.
- **Protected Member `c`**
  - Inside `std::stack`, the underlying container is stored in a protected member `c`.
  - By inheriting from `std::stack`, we can access `c` and expose its iterators.
- **Iterators**
  - `begin()`, `end()`, `rbegin()`, `rend()` can be exposed directly from the underlying container.
- **Comparison with Other Containers**
  - When iterated, `MutantStack` should behave like `std::list` or any other iterable container.

### Key Concepts
- Adapters vs Containers → `stack` is an adapter.
- Inheritance allows extending STL containers with new features.
- Iterators unify access, so any STL algorithm can work with `MutantStack`.

---

## 📚 Summary of STL Concepts

1. **Containers**
   - `vector` → dynamic array, fast random access.
   - `list` → doubly linked list, fast insertion/removal.
   - `deque` → double-ended queue, default for `stack`.
   - `multiset` → balanced tree, keeps elements sorted automatically.

2. **Iterators**
   - Generalized pointers for traversing containers.
   - Types: `iterator`, `const_iterator`, `reverse_iterator`.

3. **Algorithms**
   - Found in `<algorithm>`, they operate on ranges via iterators.
   - Examples: `find`, `sort`, `min_element`, `max_element`, `count`.

4. **Exceptions**
   - Used to handle invalid operations (e.g., empty span, container overflow).

5. **Complexity**
   - Always consider time complexity when choosing between containers.
   - Example:  
     - `vector` → cheap inserts, expensive sort.  
     - `multiset` → balanced inserts, cheap sorted traversal.  

---

## ✅ What You Learn

- How to use **STL containers** (`vector`, `list`, `multiset`, `deque`).
- How to apply **STL algorithms** with iterators.
- How to design **template functions** (`easyfind`) and **custom classes** (`Span`, `MutantStack`).
- How to balance **container choice** based on algorithmic complexity.
- How to extend STL containers (e.g., adding iterators to `stack`).

---
