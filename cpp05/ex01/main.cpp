#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat b1("Alice", 2);
    Bureaucrat b2("Bob", 140);
    Form f1("TaxForm", 3, 10);
    Form f2("SecretForm", 1, 1);
    Form f3("EasyForm", 150, 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    b1.signForm(f1); // should sign
    b2.signForm(f1); // should not sign
    b1.signForm(f2); // should not sign
    b2.signForm(f3); // should sign

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    // Test exceptions for Form construction
    try {
        Form badForm("BadForm", 0, 10);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        Form badForm2("BadForm2", 10, 151);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
