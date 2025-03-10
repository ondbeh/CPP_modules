#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{}

Form::Form(std::string name, int sign_grade, int exec_grade)
	: _name(std::move(name)), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
	}
	return *this;
}

std::string const &Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &src) {
	out << "Form " << src.getName() << " is " << (src.getIsSigned() ? "" : "not ") << "signed, sign grade: "
		<< src.getSignGrade() << ", exec grade: " << src.getExecGrade();
	return out;
}


