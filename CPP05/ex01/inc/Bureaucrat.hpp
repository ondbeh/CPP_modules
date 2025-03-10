#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
private:
	std::string const _name;
	int _grade;
	Bureaucrat();
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src) = default;
	~Bureaucrat() = default;
	Bureaucrat & operator=(Bureaucrat const & src);

	[[nodiscard]] std::string const & getName() const;
	[[nodiscard]] int getGrade() const;
	Bureaucrat &incrementGrade();
	Bureaucrat &decrementGrade();

	void signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const & src);
