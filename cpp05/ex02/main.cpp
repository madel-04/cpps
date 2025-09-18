#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat b1("Alice", 2);
    Bureaucrat b2("Bob", 140);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    b1.signForm(shrub);
    b1.signForm(robo);
    b1.signForm(pardon);

    b2.signForm(shrub);
    b2.signForm(robo);
    b2.signForm(pardon);

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    // Execution tests
    b1.executeForm(shrub); // should succeed
    b1.executeForm(robo);  // should succeed
    b1.executeForm(pardon); // should fail (grade too low)

    b2.executeForm(shrub); // should fail (not signed or grade too low)
    b2.executeForm(robo);  // should fail
    b2.executeForm(pardon); // should fail

    // Exception tests
    try {
        ShrubberyCreationForm badShrub("bad");
        Bureaucrat low("Low", 150);
        low.executeForm(badShrub); // not signed
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
