#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	const std::string _target;

public:
	ShrubberyCreationForm() = delete;
	explicit ShrubberyCreationForm(std::string target) noexcept;
	ShrubberyCreationForm(ShrubberyCreationForm const & src) noexcept = default;
	~ShrubberyCreationForm() = default;
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src) noexcept;

	void takeAction(Bureaucrat const & executor) const override;
};
