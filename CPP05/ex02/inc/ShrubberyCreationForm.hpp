#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
public:
	ShrubberyCreationForm() = delete;
	explicit ShrubberyCreationForm(std::string target) noexcept;
	ShrubberyCreationForm(ShrubberyCreationForm const &src) noexcept = default;
	~ShrubberyCreationForm() = default;

	void takeAction(Bureaucrat const &executor) const override;
};
