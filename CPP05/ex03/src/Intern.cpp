#include "../inc/Intern.hpp"

Intern::Intern() {
	_formTypes[0] = {"presidential pardon", &Intern::createPresidentialPardonForm};
	_formTypes[1] = {"robotomy request", &Intern::createRobotomyRequestForm};
	_formTypes[2] = {"shrubbery creation", &Intern::createShrubberyCreationForm};
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	if (this != &src) {
		for (int i = 0; i < FORM_TYPES; i++) {
			_formTypes[i] = src._formTypes[i];
		}
	}
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	for (int i = 0; i < FORM_TYPES; i++) {
		if (name == _formTypes[i].name) {
			return (this->*_formTypes[i].create)(target);
		}
	}
	std::cerr << "Intern cannot create form " << name << std::endl;
	return nullptr;
}

AForm *Intern::createPresidentialPardonForm(std::string target) const {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target) const {
	return new ShrubberyCreationForm(target);
}