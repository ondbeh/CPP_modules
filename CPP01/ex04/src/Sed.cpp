#include "Sed.hpp"

bool Sed::replace(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    std::string outfile_name = filename + ".replace";
    std::ofstream outfile(outfile_name);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << outfile_name << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }

    infile.close();
    outfile.close();
    return true;
}