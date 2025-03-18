#include <iostream>
#include <list>
#include <random>
#include "../inc/Span.hpp"

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try {
		Span largeSpan(1000000);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution <> distrib(1, 1410065408);

		std::vector <int> randomNumbers;
		randomNumbers.reserve(1000000);
		for (int i = 0; i < 1000000; ++i)
			randomNumbers.push_back(distrib(gen));

		largeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
		std::cout << "\nLarge span test (1,000,000 numbers):" << std::endl;
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nTesting exceptions:" << std::endl;
		Span smallSpan(1);
		smallSpan.addNumber(42);
		smallSpan.addNumber(24); // <-- Span full, exception
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Span emptySpan(10);
		emptySpan.shortestSpan(); // <-- Span empty, exception
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}