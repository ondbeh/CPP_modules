#include "../inc/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(std::move(name)), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat &Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
	return *this;
}

Bureaucrat &Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}

