#include <iostream>
#include "../inc/Bureaucrat.hpp"

int main (void)
{
	try
	{
		Bureaucrat b("John", 1);
		std::cout << b << std::endl;
		try { b.incrementGrade(); }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
		std::cout << b << std::endl;
		try { b.decrementGrade(); }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
		std::cout << b << std::endl;
		Bureaucrat a("Jack", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat c("Jane", 150);
	std::cout << c << std::endl;
	try {c.decrementGrade();}
	catch (std::exception & e) {std::cerr << e.what() << std::endl;}
	std::cout << c << std::endl;
	try {c.incrementGrade();}
	catch (std::exception & e){std::cerr << e.what() << std::endl;}
	std::cout << c << std::endl;

	Bureaucrat d ({"default", 175});
	std::cout << d << std::endl;

	return  0;
}