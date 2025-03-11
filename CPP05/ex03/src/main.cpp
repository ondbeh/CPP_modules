#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include <ctime>
#include <cstdlib>

int main(void) {
	std::srand(std::time(nullptr));
	// Intern test
	Intern intern;
	Bureaucrat bureaucrat("Bureaucrat", 10);
	AForm *form = intern.makeForm("shrubbery creation", "home");
	if (form) {
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	form = intern.makeForm("robotomy request", "home");
	if (form) {
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	form = intern.makeForm("presidential pardon", "home");
	if (form) {
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	form = intern.makeForm("unknown", "home");
	if (form) {
		std::cout << *form << std::endl;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	else {
		std::cout << "Form is nullptr" << std::endl;
	}

	return 0;
}