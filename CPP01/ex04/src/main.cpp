#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
		return 1;
	}
	if(!Sed::replace(argv[1], argv[2], argv[3]))
		return 1;
	return 0;
}