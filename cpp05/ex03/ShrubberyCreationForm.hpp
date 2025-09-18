#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm(const std::string& target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
