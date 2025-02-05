#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>

class Sed {
public:
	static bool replace(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif