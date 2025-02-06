#include "../inc/Harl.hpp"

Harl::Harl()
{
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";

	_complaints[0] = &Harl::debug;
	_complaints[1] = &Harl::info;
	_complaints[2] = &Harl::warning;
	_complaints[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-"
				 "triple-pickle-special-ketchup-burger. I really do!" << std::endl;
}

void Harl::info() const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
				 "years whereas you started working here since last month." << std::endl;
}

void Harl::error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string level) const
{
	for (int i = 0; i < 4; ++i)
	{
		if (_level[i] == level)
		{
			(this->*_complaints[i])();
			return;
		}
	}
	std::cerr << "Invalid level: " << level << std::endl;
}