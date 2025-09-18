#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(AForm& f) const {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

    void Bureaucrat::executeForm(AForm const & form) const {
        try {
            form.execute(*this);
            std::cout << _name << " executed " << form.getName() << std::endl;
        } catch (std::exception& e) {
            std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
        }
    }
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
