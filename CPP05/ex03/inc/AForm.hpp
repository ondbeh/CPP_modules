#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	std::string _target;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	AForm() = delete;
	AForm(std::string name, std::string target, int sign_grade, int exec_grade);
	AForm(AForm const & src) = default;
	~AForm() = default;
	AForm & operator=(AForm const & src);

	[[nodiscard]] std::string const & getName() const;
	[[nodiscard]] bool getIsSigned() const;
	[[nodiscard]] int getSignGrade() const;
	[[nodiscard]] int getExecGrade() const;
	[[nodiscard]] std::string const & getTarget() const;

	void beSigned(Bureaucrat const &bureaucrat);

	void execute(Bureaucrat const & executor) const;
	virtual void takeAction(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
	class FormNotSignedException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &out, AForm const & src);
