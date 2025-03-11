#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORM_TYPES 3

class Intern {
private:
	typedef struct {
		std::string name;
		AForm *(Intern::*create)(std::string) const;
	} formType;

	AForm *createPresidentialPardonForm(std::string target) const;
	AForm *createRobotomyRequestForm(std::string target) const;
	AForm *createShrubberyCreationForm(std::string target) const;

	formType _formTypes[FORM_TYPES];
public:
	Intern();
	Intern(const Intern &src);
	~Intern() = default;
	Intern &operator=(const Intern &src);

	[[nodiscard]] AForm *makeForm(std::string name, std::string target);
};
