#include "Intern.hpp"

Intern::Intern() {
    // Constructor
}
Intern::Intern(const Intern &other) {
    // Copy constructor
    (void)other;
}
Intern &Intern::operator=(const Intern &other) {
    // Assignment operator
    (void)other;
    return *this;
}
Intern::~Intern() {
    // Destructor
}   

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            // Clean up unused forms
            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    delete forms[j];
                }
            }
            return forms[i];
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    // Clean up all forms if none matched
    for (int j = 0; j < 3; ++j) {
        delete forms[j];
    }
    return NULL;
}