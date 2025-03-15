#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../inc/easyfind.hpp"

int main() {
	std::vector <int> vec = {1, 2, 3, 4, 5};

	std::cout << "Testing with vector:" << std::endl;
	try {
		auto it = easyfind(vec, 1);
		std::cout << "Found value 1 at position: " << std::distance(vec.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(vec, 10);
		std::cout << "Found value 10 at position: " << std::distance(vec.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::list <int> lst = {10, 20, 30, 40, 50};
	std::cout << "\nTesting with list:" << std::endl;
	try {
		auto it = easyfind(lst, 30);
		std::cout << "Found value 30 at position: " << std::distance(lst.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(lst, 100);
		std::cout << "Found value 100 at position: " << std::distance(lst.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::deque <int> deq = {5, 15, 25, 35, 45};
	std::cout << "\nTesting with deque:" << std::endl;
	try {
		auto it = easyfind(deq, 45);
		std::cout << "Found value 45 at position: " << std::distance(deq.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		auto it = easyfind(deq, 50);
		std::cout << "Found value 50 at position: " << std::distance(deq.begin(), it) << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}