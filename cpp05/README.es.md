
# Módulo C++ 05 – Simulador de Burocracia  


[![en](https://img.shields.io/badge/lang-English-blue.svg)](README.md)
[![es](https://img.shields.io/badge/lang-Español-red.svg)](README.es.md)


Este proyecto forma parte de los **módulos de C++ de 42 École**.  
Introduce el uso de **excepciones**, **clases abstractas** y **polimorfismo** simulando una burocracia distópica con **Burócratas**, **Formularios** y un **Becario** (*Intern*).  

---

## 📚 Objetivos de Aprendizaje  

- Dominar el **manejo de excepciones** (`throw`, `try`, `catch`)  
- Aplicar la **Forma Canónica Ortodoxa** (Regla de 3/5)  
- Trabajar con **clases abstractas** y herencia  
- Implementar **sobrecarga de operadores** (`<<`)  
- Practicar **polimorfismo** y asignación dinámica  

---

## 📂 Estructura del Proyecto  

**ex00/**  
├── Makefile  

├── main.cpp  

├── Bureaucrat.hpp / Bureaucrat.cpp  

**ex01/**  
├── Makefile  

├── main.cpp  

├── Bureaucrat.hpp / Bureaucrat.cpp  

├── Form.hpp / Form.cpp  

**ex02/**  
├── Makefile  

├── main.cpp  

├── Bureaucrat.hpp / Bureaucrat.cpp  

├── AForm.hpp / AForm.cpp  

├── ShrubberyCreationForm.hpp / ShrubberyCreationForm.cpp  

├── RobotomyRequestForm.hpp / RobotomyRequestForm.cpp  

├── PresidentialPardonForm.hpp / PresidentialPardonForm.cpp  

**ex03/**  
├── Makefile  

├── main.cpp  

├── Bureaucrat.hpp / Bureaucrat.cpp  

├── AForm.hpp / AForm.cpp  

├── ShrubberyCreationForm.hpp / ShrubberyCreationForm.cpp  

├── RobotomyRequestForm.hpp / RobotomyRequestForm.cpp  

├── PresidentialPardonForm.hpp / PresidentialPardonForm.cpp  

├── Intern.hpp / Intern.cpp  

---

## Repaso de Teoría de C++  

### Excepciones en C++  

Lanzar una excepción:  
```cpp
if (grade < 1)
    throw GradeTooHighException();
else if (grade > 150)
    throw GradeTooLowException();
````

Capturar excepciones:

```cpp
try 
{
  Bureaucrat b("Bob", 200);
}
catch (std::exception &e)
{
  std::cerr << e.what() << std::endl;
}
```

Excepción personalizada:

```cpp
class GradeTooHighException : public std::exception {
    const char* what() const throw() { return "¡La nota es demasiado alta!"; }
};
```

---

### Sobrecarga de Operadores

La sobrecarga de operadores permite redefinir cómo funcionan los operadores para tus propias clases.
De esta manera, puedes usar operadores (+, -, <<, ==, etc.) con objetos igual que con tipos primitivos.

Con `<<` (inserción en flujo):

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

// Sobrecarga de << fuera de la clase
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", grado de burócrata " << b.getGrade();
    return out;
}
```

Uso:

```cpp
Bureaucrat b("Alice", 3);
std::cout << b << std::endl;
```

Salida:

```cpp
Alice, grado de burócrata 3
```

#### Corrección con `const`

Se debe usar `const` cuando un atributo o método no debería modificar el objeto.

---

## 📝 Desglose de Ejercicios

### **ex00 – Bureaucrat**

* Clase `Bureaucrat`:

  * `const std::string name`
  * `int grade` (1 = mejor, 150 = peor)
* Excepciones:

  * `GradeTooHighException`
  * `GradeTooLowException`
* Métodos:

  * `getName()`, `getGrade()`
  * `incrementGrade()`, `decrementGrade()` (lanza excepciones si se sale de rango)
* Sobrecarga del operador `<<`.

---

### **ex01 – Form**

* Clase `Form`:

  * `const std::string name`
  * `bool isSigned`
  * `const int gradeToSign`
  * `const int gradeToExecute`
* Excepciones: `GradeTooHighException`, `GradeTooLowException`
* Métodos:

  * Getters de todos los atributos
  * `beSigned(Bureaucrat&)`
  * `Bureaucrat` obtiene `signForm(Form&)`
* Sobrecarga del operador `<<` para imprimir información del formulario.

---

### **ex02 – Formularios Abstractos**

* Convertir `Form` en **clase abstracta `AForm`**.
* Añadir clases derivadas:

  * **ShrubberyCreationForm** → crea `<target>_shrubbery` con árboles ASCII 🌳
  * **RobotomyRequestForm** → 50% de probabilidad de robotomía exitosa 🤖
  * **PresidentialPardonForm** → `<target> ha sido indultado por Zaphod Beeblebrox`
* Todos requieren notas específicas para firmar/ejecutar.
* Burócrata:

  * `executeForm(AForm const & form)`

---

### **ex03 – Intern (Becario)**

* Clase `Intern`:

  * `makeForm(std::string formName, std::string target)`
* Crea formularios:

  * `"shrubbery creation"`
  * `"robotomy request"`
  * `"presidential pardon"`
* Mensajes:

  * Maneja nombres inválidos con un mensaje de error.
  * La implementación debe **evitar cadenas excesivas de if/else**.

