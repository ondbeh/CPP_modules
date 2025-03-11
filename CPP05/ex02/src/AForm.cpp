#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade)
		: _name(std::move(name)), _target(std::move(target)),
		  _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1) {
		throw AForm::GradeTooHighException();
	}
	if (sign_grade > 150 || exec_grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
		_target = src._target;
	}
	return *this;
}

std::string const &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getSignGrade() const {
	return _sign_grade;
}

int AForm::getExecGrade() const {
	return _exec_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign_grade) {
		throw AForm::GradeTooLowException();
	}
	_is_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_is_signed) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _exec_grade) {
		throw AForm::GradeTooLowException();
	}
	takeAction(executor);
}

std::string const &AForm::getTarget() const {
	return _target;
}

const char *AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const noexcept {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
	out << "AForm " << src.getName() << " is " << (src.getIsSigned() ? "" : "not ") << "signed, sign grade: "
		<< src.getSignGrade() << ", exec grade: " << src.getExecGrade();
	return out;
}
