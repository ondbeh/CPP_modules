#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main (void)
{
	Bureaucrat b("John", 1);
	std::cout << b << std::endl;
	ShrubberyCreationForm f("home");
	std::cout << f << std::endl;
	b.executeForm(f);
	b.signForm(f);
	std::cout << f << std::endl;
	b.executeForm(f);

	return  0;
}