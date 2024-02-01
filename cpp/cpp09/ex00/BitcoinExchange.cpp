#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printFiles()
{
    //std::map<std::string, double>::iterator it;
    // for (it = inputData.begin(); it != inputData.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }
    // for (it = csvData.begin(); it != csvData.end(); ++it) {
    //     std::cout <<", Value: " << it->second << std::endl;
    // }
}

void BitcoinExchange::calAndPrint()
{
    std::ifstream file(inputFilePath);
    std::string line;
    if (!file.is_open())
        throw CanNotOpenFile();

    while (std::getline(file, line))
    {
        if (!isValidLine(line))
            continue;
        double rate;
        std::string date;
        size_t cut = line.find(" | ");
        if (cut == SIZE_T_MAX)
        {
            date = "bad input";
            rate = 0;
        }
        else
        {
            line.replace(cut, 3, ",");
            date = line.substr(0, line.find(','));
            std::stringstream(line.substr(line.find(',') + 1)) >> rate;
            std::cout.precision(7);
            csvData.insert(std::make_pair(date, rate));
        }
    }
	file.close();
}

BitcoinExchange::BitcoinExchange(char *input) : inputFilePath(std::string(input))
{
    setFile();
    calAndPrint();
    printFiles();
}

bool BitcoinExchange::isValidLine(std::string line) const
{
    std::list<int> date;
    for (int i = 0; i < 3; i++)
    {
        std::cout << line << std::endl;
        size_t delIdx = line.find('-');
        if (delIdx == SIZE_T_MAX)
        {
            delIdx = line.find(' ');
            if (delIdx == SIZE_T_MAX)
            {
                std::cout<<"ERROR: bad input"<<std::endl;
                return false;
            }
        }
        std::istringstream iss(line.substr(0, delIdx));
        int result;
        iss >> result;
        date.push_back(result);
        line += delIdx;
    }
    std::list<int>::iterator it;
    for (it = date.begin(); it != date.end(); ++it) {
        std::cout << "Value: " << *it << std::endl;
    }
    return true;
}

void BitcoinExchange::setFile()
{
	std::ifstream file("data.csv");
    std::string line;
    if (!file.is_open())
        throw CanNotOpenFile();

    while (std::getline(file, line))
    {
        double rate;
        std::string date;
        date = line.substr(0, line.find(','));
        std::stringstream(line.substr(line.find(',') + 1)) >> rate;
        std::cout.precision(7);
        csvData.insert(std::make_pair(date, rate));
    }
	file.close();
}

const char* BitcoinExchange::CanNotOpenFile::what() const throw()
{
	return "Error: could not open file.";
}
