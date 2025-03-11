#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main(void) {
	std::srand(std::time(nullptr));
	Bureaucrat b("John", 10);
	Bureaucrat president("Zaphod Beeblebrox", 1);
	std::cout << b << std::endl;
	ShrubberyCreationForm f("home");
	RobotomyRequestForm r("Pepa");
	PresidentialPardonForm p("Pepa");
	std::cout << f << std::endl;
	b.executeForm(f);
	b.signForm(f);
	b.signForm(r);
	b.signForm(p);
	std::cout << f << std::endl;
	b.executeForm(f);
	b.executeForm(r);
	b.executeForm(p);
	president.executeForm(p);
	return 0;
}