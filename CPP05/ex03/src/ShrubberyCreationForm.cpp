#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) noexcept:
		AForm("ShrubberyCreationForm", std::move(target), 145, 137) {}

void ShrubberyCreationForm::takeAction(Bureaucrat const &) const {
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file.is_open()) {
		throw std::runtime_error("Cannot open file");
	}
	file << "       _-_\n"
		 << "    /~~   ~~\\\n"
		 << " /~~         ~~\\\n"
		 << "{               }\n"
		 << " \\  _-     -_  /\n"
		 << "   ~  \\\\ //  ~\n"
		 << "_- -   | | _- _\n"
		 << "  _ -  | |   -_\n"
		 << "      // \\\\" << std::endl;
}





