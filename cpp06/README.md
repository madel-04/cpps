# C++ Module 06

[![en](https://img.shields.io/badge/lang-English-blue.svg)](README.en.md)
[![es](https://img.shields.io/badge/lang-Español-red.svg)](README.md)

## Exercise 00: ScalarConverter

### 📌 Enunciado resumido
Implementar una clase **`ScalarConverter`** que contenga un único método estático:

```cpp
static void convert(const std::string& literal);
```
El método recibe una cadena que representa un literal de C++ y debe convertirlo a los cuatro tipos escalares básicos:
- Char
- Int
- Float
- Double

La clase **no debe ser instanciable** (constructores/destructores privados o borrados). 

#### Clase no instanciable

Que no sea instanciable significa que nadie pueda hacer por ejemplo:
```cpp
Serializer s;             // constructor por defecto
Serializer* p = new Serializer(); // constructor + destructor
Serializer s2 = s;        // constructor de copia
s = s2;                   // operador de asignación

```
Para impedirlo, basta con declarar los constructores/destructores/copias como  *private*. De ese modo, cualquier intento de usarlos genera error de compilación.

No hace falta definirlos dentro del cpp porque nunca se van a usar. Nadie fuera de la clase va a poder llamarlos porque están privados y dentro de la misma clase tampoco los usamos. 

Como alternativa en C++ 11+, se puede hacer explicitamente con < delete >. 

```cpp
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

    Serializer() = delete;
    Serializer(const Serializer&) = delete;
    Serializer& operator=(const Serializer&) = delete;
    ~Serializer() = delete;
};

```


### Objetivos del ejercicio
1. Detectar el tipo real del literal recibido como `std::string`.
2. Convertirlo a su tipo base (char, int, float, double)
3. Realizar conversiones explícitas al resto de tipos.
4. Mostrar el resultado en un formato preciso y claro como muestra el enunciado en el ejemplo.
5. Gestionar casos especiales:
    - Psudo-litersles: nan, nanf,+inf, -inf, +inff, -inff
    - Valores fuera de rango (`int` overflow)
    - Caracteres no imprimibles

### Conceptos claves

#### Conversión de tipos en C++
- **Cast implícito**: el compilador convierte automáticamente entre tipos compatibles (ej: int → double).

- **Cast explícito**: el programador fuerza la conversión usando static_cast, dynamic_cast, reinterpret_cast o const_cast.
Para este ejercicio basta con static_cast.

Ejemplo:
```cpp
double d = 42.0;
int i = static_cast<int>(d);   // convierte double → int
char c = static_cast<char>(i); // convierte int → char
```

#### Literales en C++
- Char literal: 'a', 'Z'.
- Int literal: 42, -7
- Float literal: 4.2f, -0.0f. Siempre terminan en f.
- Double literal: 4.2, -0.0.
- Pseudo-literals: nan, nanf, +inf, -inf, +inff, -inff.

#### Librerias útiles
- <string>: manipulación de cadenas.
- <iostream>: entrada/salida.
- <limits>: obtener rangos (std::numeric_limits<int>::max()).
- <iomanip>: control de formato (std::setprecision).
- <cmath>: funciones matemáticas (std::isnan, std::isinf).
- <cctype>: comprobar caracteres (std::isdigit, isprint).

#### Detección del tipo
El algoritmo sigue reglas simples:
- Char: longitud 1 y no es un dígito.
- Int: solo dígitos (con + o - opcional).
- Float: contiene . y termina en f o es pseudo-literal (nanf, +inff, -inff).
- Double: contiene . y no termina en f, o es pseudo-literal (nan, +inf, -inf).
- Otros: tipo no reconocido → conversiones imposibles.

#### Manejo de excepciones

El valor se guarda como <double> para facillitar las conversiones a los demás tipos.

- std::stoi, std::stoll, std::stof, std::stod pueden lanzar std::out_of_range o std::invalid_argument.
- Capturar excepciones permite marcar conversiones imposibles sin detener la ejecución

## Excercise 01: Serialization

### 📌 Enunciado resumido
Implementar una clase **`Serializer`** que no pueda ser instanciada y que ofrezca dos métodos estáticos:

```cpp
static uintptr_t serialize(Data* ptr);
static Data* deserialize(uintptr_t raw);
```
serialize: convierte un puntero (Data*) en un entero sin signo (uintptr_t).

deserialize: convierte ese entero (uintptr_t) de nuevo en un puntero (Data*).

Además se debe definir una estructura Data con algunos miembros, y demostrar en un programa que serializar y luego deserializar devuelve el puntero al original.

### Objetivos del ejercicio
1. Praticar la reinterpretación de punteros con <reinterpret_cast>
2. Entender el uso del tipo uintptr_t para almadcenar direcciones de memoria.
3. Comprobar que un puntero se puede "señalizar" en un entero y luego recuperar correctamente. 
4. Usar una estructura con datos reales para validar el proceso.

### Conceptos claves

#### ¿Qué es uintptr_t?
Es un entero sin signo definido en <cstdint>. Está garantizado par poder almacenar una dirección de memoria sin perdida de información

```cpp
int x = 10;
int* ptr = &x;
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);

```

#### ¿Qué es reinterpret_cast?

Es un cast de C++ que permitr convertir entre tipos de punteros y enteros. No altera el valor en memoria, solo **reinterpreta los bits**. 