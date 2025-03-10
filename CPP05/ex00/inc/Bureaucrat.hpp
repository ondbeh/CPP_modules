#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
	class GradeTooHighException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		[[nodiscard]] const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const & src);

#endif //BUREAUCRAT_HPP
