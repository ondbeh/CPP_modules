#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;

	typedef void (Harl::*ComplaintFunc)() const;
	ComplaintFunc _complaints[4];
	std::string _level[4];

public:
	Harl();
	~Harl();
	void complain(const std::string level) const;
};

#endif // HARL_HPP