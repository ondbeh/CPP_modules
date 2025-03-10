#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main (void)
{
	Bureaucrat b("John", 1);
	Form f("Form", 1, 1);
	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	Bureaucrat b2("John", 150);
	Form f2("Form", 50, 75);
	std::cout << b2 << std::endl;
	std::cout << f2 << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	b.signForm(f2);
	std::cout << f2 << std::endl;
	return  0;
}