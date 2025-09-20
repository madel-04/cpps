# C++ Module 05 – Bureaucracy Simulator

This project is part of **42 École's C++ modules**.  
It introduces **exceptions**, **abstract classes**, and **polymorphism** by simulating a dystopian bureaucracy with **Bureaucrats**, **Forms**, and an **Intern**.

---

## 📚 Learning Objectives

- Master **exception handling** (`throw`, `try`, `catch`)
- Apply the **Orthodox Canonical Form** (Rule of 3/5)
- Work with **abstract classes** and inheritance
- Implement **operator overloading** (`<<`)
- Practice **polymorphism** and dynamic allocation

---

## 📂 Project Structure

ex00/

├── Makefile

├── main.cpp

├── Bureaucrat.hpp / Bureaucrat.cpp

ex01/

├── Makefile

├── main.cpp

├── Bureaucrat.hpp / Bureaucrat.cpp

├── Form.hpp / Form.cpp

ex02/

├── Makefile

├── main.cpp

├── Bureaucrat.hpp / Bureaucrat.cpp

├── AForm.hpp / AForm.cpp

├── ShrubberyCreationForm.hpp / ShrubberyCreationForm.cpp

├── RobotomyRequestForm.hpp / RobotomyRequestForm.cpp

├── PresidentialPardonForm.hpp / PresidentialPardonForm.cpp

ex03/

├── Makefile

├── main.cpp

├── Bureaucrat.hpp / Bureaucrat.cpp

├── AForm.hpp / AForm.cpp

├── ShrubberyCreationForm.hpp / ShrubberyCreationForm.cpp

├── RobotomyRequestForm.hpp / RobotomyRequestForm.cpp

├── PresidentialPardonForm.hpp / PresidentialPardonForm.cpp

├── Intern.hpp / Intern.cpp


---

## C++ Theory Recap

### Exceptions in C++
Throwing an exception:
```cpp
if (grade < 1)
    throw GradeTooHighException();
else if (grade > 150)
    throw GradeTooLowException();
```

Catching Exceptions:
```cpp
try 
{
  Bureaucrat b("Bob", 200);
}
catch (std::exception &e)
{
  std::cerr <<e.what() << std::endl;
}

Custom exception:
```cpp
class GradeTooHighException : public std::exception {
    const char* what() const throw() { return "Grade is too high!"; }
};
```

### Operator Overloading
Operator overloading lets you redefine how operators work for your own classes.
This way, you can use operators (+, -, <<, ==, etc.) with objects just like you do with primitive types.

With << (stream insertion):
```cpp
class Bureaucrat {
private:
    std::string name;
    int grade;
public:
    Bureaucrat(std::string n, int g) : name(n), grade(g) {}
    std::string getName() const { return name; }
    int getGrade() const { return grade; }
};

// Overload << outside the class
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

```

Usage:
```cpp
Bureaucrat b("Alice", 3);
std::cout << b << std::endl;
```

Output:
```cpp
Alice, bureaucrat grade 3
```

#### Const Correctness
You should use ```const```when an attribute or method should not modify the object.

---

## 📝 Exercises Breakdown

### **ex00 – Bureaucrat**
- Class `Bureaucrat`:
    - `const std::string name`
    - `int grade` (1 = best, 150 = worst)
- Exceptions:
    - `GradeTooHighException`
    - `GradeTooLowException`
- Methods:
    - `getName()`, `getGrade()`
    - `incrementGrade()`, `decrementGrade()` (throws on out-of-bounds)
- Operator `<<` overload:


---

### **ex01 – Form**
- Class `Form`:
  -  `const std::string name`
  - `bool isSigned`
  - `const int gradeToSign`
  - `const int gradeToExecute`
- Exceptions: `GradeTooHighException`, `GradeTooLowException`
  - Methods:
  - Getters for all attributes
  - `beSigned(Bureaucrat&)`
  - `Bureaucrat` gains `signForm(Form&)`
- Operator `<<` overload prints form info.

---

### **ex02 – Abstract Forms**
- Convert `Form` into **abstract class `AForm`**.
- Add derived forms:
  - **ShrubberyCreationForm** → creates `<target>_shrubbery` with ASCII trees 🌳
  - **RobotomyRequestForm** → 50% chance of successful robotomy 🤖
  - **PresidentialPardonForm** → `<target> has been pardoned by Zaphod Beeblebrox`
- All require specific grades to sign/execute.
  - Bureaucrat:
    - `executeForm(AForm const & form)`

---

### **ex03 – Intern**
- Class `Intern`:
  - `makeForm(std::string formName, std::string target)`
- Creates forms:
  - `"shrubbery creation"`
  - `"robotomy request"`
  - `"presidential pardon"`
- Prints:
  - Handles invalid names with an error message.
  - Implementation should **avoid excessive if/else chains**.

---
