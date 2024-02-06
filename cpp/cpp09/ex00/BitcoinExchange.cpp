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
    std::list<std::string> parsedData;
    if (!file.is_open())
        throw CanNotOpenFile();

    while (std::getline(file, line))
    {
        if (line == "date | value")
            continue;
        parsedData = parsingData(line);
        if (!isValidData(parsedData))
            continue;
        double rate;
        std::string date = line.substr(0, 10);
        findTargetDate(date);
        // size_t cut = line.find(" | ");
        // line.replace(cut, 3, ",");
        // date = line.substr(0, line.find(','));
        // std::stringstream(line.substr(line.find(',') + 1)) >> rate;
        // std::cout.precision(7);
        // csvData.insert(std::make_pair(date, rate));
    }
	file.close();
}

std::string BitcoinExchange::findTargetDate(std::string date) const
{

}

bool BitcoinExchange::isValidData(std::list<std::string> input) const
{
    std::list<std::string>::iterator it;
    int idx = 0;
    
    for (it = input.begin(); it != input.end(); ++it, ++idx) {
        std::istringstream iss(*it);
        float result;
        iss >> result;

        if (idx == 0) {
            if (result < 0 || result > 3000) {
                std::cout << "Error: bad input => " << *it << std::endl;
                return false;
            }
        } else if (idx == 1) {
            if (result <= 0 || result > 12) {
                std::cout << "Error: bad input => " << *it << std::endl;
                return false;
            }
        } else if (idx == 2) {
            if (result <= 0 || result > 31) {
                std::cout << "Error: bad input => " << *it << std::endl;
                return false;
            }
        } else if (idx == 3) {
            if (result < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                return false;
            } else if (result > 1000) {
                std::cout << "Error: too large a number." << std::endl;
                return false;
            }
        }
    }
    return true;
}

BitcoinExchange::BitcoinExchange(char *input) : inputFilePath(std::string(input))
{
    setFile();
    calAndPrint();
    printFiles();
}

std::list<std::string> BitcoinExchange::parsingData(std::string line) const
{
    std::list<std::string> ret;

    ret.push_back(line.substr(0, 4));
    ret.push_back(line.substr(5, 2));
    ret.push_back(line.substr(8, 2));
    size_t lastSpacePos = line.find_last_of(' ');
    ret.push_back(line.substr(lastSpacePos + 1));

    std::list<std::string>::iterator it;
    for (it = ret.begin(); it != ret.end(); ++it) {
        std::cout << "Key: " << *it << std::endl;
    }
    return ret;
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
