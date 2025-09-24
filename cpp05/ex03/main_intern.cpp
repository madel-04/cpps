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
