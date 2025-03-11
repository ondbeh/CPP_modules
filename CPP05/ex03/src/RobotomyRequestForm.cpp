#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) noexcept:
		AForm("RobotomyRequestForm", std::move(target), 72, 45) {}

void RobotomyRequestForm::takeAction(Bureaucrat const &) const {
	if (std::rand() % 2) {
		throw std::runtime_error("Robotomization failed");
	}
	else {
		std::cout << "VR!!! VRRRRR!!! VRRRRRRRRR!!! " << getTarget()
				  << " has been robotomized successfully!" << std::endl;
	}
}