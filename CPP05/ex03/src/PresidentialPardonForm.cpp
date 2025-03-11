#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) noexcept:
		AForm("PresidentialPardonForm", std::move(target), 25, 5) {}

void PresidentialPardonForm::takeAction(Bureaucrat const &executor) const {
	std::cout << getTarget() << " has been pardoned by "
			  << executor.getName() << std::endl;
}