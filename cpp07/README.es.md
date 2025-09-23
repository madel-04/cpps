# C++ Module 07

[![en](https://img.shields.io/badge/lang-English-blue.svg)](README.md)
[![es](https://img.shields.io/badge/lang-Español-red.svg)](README.es.md)

## Exercise 00: Empezamos con unas pocas funciones

### 📌 Summary
Implementar tres funciones que puedan comparar dos parametros independientemente del tipo, con la condición de que ambos sean del mismo tipo. 
 - <swap()> : cambia los dos valores, no devuelve nada.
 - <min()> : compara los valores y devuelve el más pequeño. Si son iguales devuelve el segundo.
 - <max()> : compara los valores y devuelve el más grande, si son iguales devuelve el segundo.

#### "Template"

La expresión <template <typename T>> en C++ se utiliza para declarar una plantilla, que es una forma de escribir código genérico que puede trabajar con diferentes tipos de datos sin tener que duplicar código para cada tipo específico

Un template permite definir funciones o clases con parámetros de tipo, que actúan como marcadores de posición para un tipo de dato que se decidirá cuando se utilice esa función o clase. Se pueden usar tanto para funciones como para clases. El compilador genera el código concreto según el tipo que se utilice. 

Ejemplo de función:
```cpp
template <typename T>
T sumar(T a, T b) {
    return a + b;
}
```

Ejemplo de clase:
```cpp
template <typename T>
class Caja {
    T contenido;
public:
    Caja(T contenido) : contenido(contenido) {}
    T obtenerContenido() { return contenido; }
};
```

La palabra clave typename se emplea para indicar que el parámetro es de tipo y puede usarse indistintamente con class en la declaración. Ambas cumplen la misma función en el contexto de templates, aunque typename es obligatoria en algunos contextos dentro de plantillas más complejas.
