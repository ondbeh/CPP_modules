#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
	PresidentialPardonForm() = delete;
	explicit PresidentialPardonForm(std::string target) noexcept;
	PresidentialPardonForm(PresidentialPardonForm const &src) noexcept = default;
	~PresidentialPardonForm() = default;

	void takeAction(Bureaucrat const &executor) const;
};
