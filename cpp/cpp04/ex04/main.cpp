#include <iostream>
#include <fstream>
#include <iosfwd>
#include <sstream>

int printError(std::string str)
{
    std::cerr << "ERROR : " + str << std::endl;
    return (-1);
}

int main( int argc, char *argv[] )
{
    if (argc != 4)
        return(printError("parameters should be four"));
    
    std::ifstream fin;
	std::ofstream fout;
    std::ostringstream oss;
    std::string istr;

    fin.open(argv[1]);
    if (fin.fail())
        return(printError("input file error"));
    
    fout.open(std::string(argv[1]) + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (fout.fail())
    {
        fin.close();
        return(printError("output file error"));
	}
    
    oss << fin.rdbuf();
	istr = oss.str();
    std::string ostr = "";
    size_t idx = 0;
    std::string searchStr = argv[2];
    std::string replaceStr = argv[3];

    while (istr.find(searchStr, idx) != std::string::npos)
    {
        size_t pos = istr.find(searchStr, idx);
        ostr += istr.substr(idx, pos - idx);
        ostr += replaceStr;
        idx += pos + searchStr.length();
    }
    ostr += &(istr[idx]);
    fout << ostr;

    fin.close();
    fout.clear();
    return (0);
    
}

