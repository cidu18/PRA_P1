#include <iostream>
#include <stdexcept>
#include <cassert> // Para validaciones automáticas
#include "Shape.h"

void test_success() {
    std::cout << "--- Ejecutando pruebas de éxito ---" << std::endl;

    // Probar constructor por defecto
    Shape s1;
    std::cout << "Color por defecto (esperado 'red'): " << s1.get_color() << std::endl;
    assert(s1.get_color() == "red");

    // Probar constructor con parámetro válido
    Shape s2("green");
    std::cout << "Color asignado 'green': " << s2.get_color() << std::endl;
    assert(s2.get_color() == "green");

    // Probar set_color válido
    s1.set_color("blue");
    std::cout << "Color cambiado a 'blue': " << s1.get_color() << std::endl;
    assert(s1.get_color() == "blue");

    std::cout << "¡Pruebas de éxito superadas!\n" << std::endl;
}

void test_exceptions() {
    std::cout << "--- Ejecutando pruebas de excepciones ---" << std::endl;

    // Caso 1: Constructor con color inválido
    try {
        std::cout << "Intentando crear Shape('yellow')..." << std::endl;
        Shape s_error("yellow");
        std::cerr << "FALLO: No se lanzó la excepción en el constructor." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "ÉXITO: Se capturó la excepción esperada: " << e.what() << std::endl;
    }

    // Caso 2: set_color con color inválido
    try {
        Shape s_valid("red");
        std::cout << "Intentando set_color('purple')..." << std::endl;
        s_valid.set_color("purple");
        std::cerr << "FALLO: No se lanzó la excepción en set_color." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "ÉXITO: Se capturó la excepción esperada: " << e.what() << std::endl;
    }

    std::cout << "¡Pruebas de excepciones superadas!\n" << std::endl;
}

int main() {
    try {
        test_success();
        test_exceptions();
        std::cout << "========================================" << std::endl;
        std::cout << "TODOS LOS TESTS HAN PASADO CORRECTAMENTE" << std::endl;
        std::cout << "========================================" << std::endl;
    } catch (...) {
        std::cerr << "Error inesperado durante la ejecución de los tests." << std::endl;
        return 1;
    }
    return 0;
}
