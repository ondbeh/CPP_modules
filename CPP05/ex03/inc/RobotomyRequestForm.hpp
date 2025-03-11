#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm {
public:
	RobotomyRequestForm() = delete;
	explicit RobotomyRequestForm(std::string target) noexcept;
	RobotomyRequestForm(RobotomyRequestForm const &src) noexcept = default;
	~RobotomyRequestForm() = default;

	void takeAction(Bureaucrat const &executor) const override;
};
