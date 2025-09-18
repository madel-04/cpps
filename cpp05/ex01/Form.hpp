#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

    void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
