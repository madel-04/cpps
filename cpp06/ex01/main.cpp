#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData = {42, "Hello serialization", 3.14};

    std::cout << "Original Data pointer: " << &myData << "\n";

    // Serializamos el puntero
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t: " << raw << "\n";

    // Deserializamos
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << ptr << "\n";

    // Verificamos igualdad de punteros
    if (ptr == &myData)
        std::cout << "✅ Deserialization successful, pointers match!\n";
    else
        std::cout << "❌ Error: pointers do not match!\n";

    // Mostrar contenido para comprobar
    std::cout << "Data.id: " << ptr->id << "\n";
    std::cout << "Data.name: " << ptr->name << "\n";
    std::cout << "Data.value: " << ptr->value << "\n";

    return 0;
}
