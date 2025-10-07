# 📘 C++ Module 09 — STL

This module introduces the **C++ Standard Template Library (STL)** and focuses on using containers and algorithms effectively.  
It contains three exercises designed to explore maps, stacks, vectors, deques, and algorithmic thinking.

---

## 🧩 Exercise 00 — BitcoinExchange

### 🗂️ Files
```

ex00/
├── Makefile

├── main.cpp

├── BitcoinExchange.cpp

└── BitcoinExchange.hpp

```

### 🧠 Concept
You must build a program that computes the value of a given amount of Bitcoin on specific dates using a CSV database of historical prices.

### ⚙️ How it works
1. **Load CSV database** into an STL container (`std::map`), storing:
```

date → exchange rate

```
2. **Read an input file** (`input.txt`) with lines like:
```

2011-01-03 | 3

```
3. **Validate** the date and value (must be positive and ≤ 1000).
4. **Find the closest earlier date** in the database if the exact one doesn’t exist.
5. **Compute the conversion** and display:
```

2011-01-03 => 3 = 0.9

```
6. **Handle errors gracefully**:
- Invalid date format → `Error: bad input => ...`
- Negative or too large value → proper error message.
- Missing file → `Error: could not open file.`

### 🧺 STL Container Used
- `std::map` — allows fast lookup by date and finding the closest lower key efficiently.

### ✅ Example Output
```

2011-01-03 => 3 = 0.9
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
Error: too large a number.

```

---

## 🧮 Exercise 01 — Reverse Polish Notation (RPN)

### 🗂️ Files
```

ex01/

├── Makefile

├── main.cpp

├── RPN.cpp

└── RPN.hpp

```

### 🧠 Concept
Evaluate mathematical expressions written in **Reverse Polish Notation (postfix)** using a stack.

### ⚙️ How it works
1. The program takes **one argument**, an RPN expression (enclosed in quotes):
```

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

```
2. Uses a **stack** (`std::stack<int>`) to process:
- Push numbers onto the stack.
- When an operator is encountered, pop two numbers, apply the operation, and push the result back.
3. After processing, the top of the stack contains the result.
4. Errors (invalid tokens, missing operands, division by zero) print:
```

Error

```

### 🧺 STL Container Used
- `std::stack` — ideal for LIFO (Last In, First Out) operations required by RPN evaluation.

### ✅ Example Output
```

$ ./RPN "7 7 * 7 -"
42
$ ./RPN "(1 + 1)"
Error

```

---

## ⚡ Exercise 02 — PmergeMe

### 🗂️ Files
```

ex02/

├── Makefile

├── main.cpp

├── PmergeMe.cpp

└── PmergeMe.hpp

```

### 🧠 Concept
Implement a **merge-insertion sort (Ford–Johnson algorithm)** using two different STL containers to compare performance.

### ⚙️ How it works
1. Program accepts a sequence of **positive integers**:
``` 

./PmergeMe 5 9 12 542100 85416516 ...

```
2. All inputs are validated — negative or invalid numbers cause:
```

Error: invalid number.

```
3. Two separate containers (`std::vector` and `std::deque`) store the numbers.
4. Each container is sorted independently using an **insertion/merge-insert algorithm**.
5. Measure and display the **time taken** for each container to sort the data.

### 🧺 STL Containers Used
- `std::vector` — contiguous memory, faster for random access.
- `std::deque` — segmented memory, slower but flexible for insertions.

### ⏱️ Output Format
```

Before: 5 9 12 542100 85416516 8465 ...
Time to process a range of 28 elements with std::vector : 3 us
Time to process a range of 28 elements with std::deque  : 13 us
After: 5 6 8 9 12 45 62 64 74 82 ...

```

### ⚙️ Algorithm Explanation
- **Insertion Sort Logic:**
  - Iterate through the container.
  - Insert each element in its proper position among the already-sorted portion.
- **Timing:**
  - Uses `clock()` from `<ctime>` to measure CPU time difference between start and end of the sort.

### ✅ Requirements Met
- Two distinct STL containers used.
- Proper time measurement.
- Error handling for invalid input.
- Handles large sequences (3000+ numbers).

---

## 🧾 Compilation

Each folder contains its own `Makefile`:
```

make
./btc input.txt
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./PmergeMe 3 5 9 7 4

```

Common compilation flags:
```

c++ -Wall -Wextra -Werror -std=c++98

```

---

## 💡 Key Takeaways

| Exercise | Main Concept | STL Container | Focus |
|-----------|---------------|----------------|--------|
| ex00 | Data lookup and validation | `std::map` | Data parsing, date handling |
| ex01 | Reverse Polish Notation | `std::stack` | Stack-based expression evaluation |
| ex02 | Sorting algorithm (Ford–Johnson / merge-insert) | `std::vector` & `std::deque` | Algorithmic efficiency & timing |

---

## 🧠 Notes for Evaluation
- Each container is used **only once** across exercises.
- Programs are **C++98 compliant**.
- No forbidden functions or headers.
- Proper error messages and clean output.
- Makefile supports rules: `all`, `clean`, `fclean`, `re`.

---

## 🏁 Author
Developed as part of **42 C++ Module 09 — STL**  
> Learning goal: Apply STL containers, understand algorithmic complexity, and write efficient, modern C++ (within C++98 limits).
