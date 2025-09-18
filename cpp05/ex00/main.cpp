#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade(); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Charlie", 0); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Dave", 151); // Should throw
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
