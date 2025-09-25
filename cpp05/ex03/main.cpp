/* #include "Bureaucrat.hpp"
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
 */

 #include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern intern;
    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    if (form1) {
        std::cout << "Form created: " << form1->getName() << " for target: Bender" << std::endl;
        delete form1;
    }

    AForm* form2 = intern.makeForm("shrubbery creation", "Garden");
    if (form2) {
        std::cout << "Form created: " << form2->getName() << " for target: Garden" << std::endl;
        delete form2;
    }

    AForm* form3 = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form3) {
        std::cout << "Form created: " << form3->getName() << " for target: Ford Prefect" << std::endl;
        delete form3;
    }

    // Test with an invalid form name
    AForm* form4 = intern.makeForm("invalid form", "Nobody");
    if (!form4) {
        std::cout << "No form created for invalid form name." << std::endl;
    }

    return 0;
}
