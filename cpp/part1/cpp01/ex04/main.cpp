#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{

    if (ac != 4 || std::string(av[2]).empty())
    {
        std::cerr << "Error args" << std::endl;
        return (1);
    }

    std::string result;
    size_t      pos = 0;
    size_t      found;
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream ifs (av[1], std::ifstream::in);
    if (!ifs.good())
    {
        std::cerr << "Error failed to open file" << std::endl;
        return (1);
    }

    std::string content;
    std::getline(ifs, content, '\0');
    if (ifs.bad())
    {
        std::cerr << "Error, wrong file" << std::endl;
        return (1);
    }
    ifs.close();

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);

    std::string outFile = std::string(av[1]) + ".replace";
    std::ofstream ofs(outFile.c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Error failed to create file " << outFile << std::endl;
        return (1);
    }
    ofs << result;
    ofs.close();
    return (0);
}
