#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	Form();
	Form(std::string name, int sign_grade, int exec_grade);
	Form(Form const & src) = default;
	~Form() = default;
	Form & operator=(Form const & src);

	[[nodiscard]] std::string const & getName() const;
	[[nodiscard]] bool getIsSigned() const;
	[[nodiscard]] int getSignGrade() const;
	[[nodiscard]] int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &out, Form const & src);
