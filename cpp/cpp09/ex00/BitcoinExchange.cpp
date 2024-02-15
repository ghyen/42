#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

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
        size_t lastSpacePos = line.find_last_of(' ');
        std::stringstream(line.substr(lastSpacePos + 1)) >> rate;
        std::string date = line.substr(0, 10);
        std::cout << date << " => " << rate << " = " << findTargetValue(date) * rate << std::endl;
    }
	file.close();
}

double BitcoinExchange::findTargetValue(const std::string& date)
{
    std::map<std::string, double>::iterator it = csvData.find(date);
    if (it != csvData.end()) {
        return it->second;
    } else {
        std::map<std::string, double>::reverse_iterator last = csvData.rbegin();
        if (last->first < date)
            return last->second;
        it = csvData.lower_bound(date);
        return std::prev(it)->second;
    }
}

bool static isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool BitcoinExchange::isValidData(std::list<std::string>& input) const
{
    std::list<std::string>::iterator it;
    int idx = 0;
    
    for (it = input.begin(); it != input.end(); ++it, ++idx) {
        std::istringstream iss(*it);
        float result;
        iss >> result;

        if (idx == 0) {
            if (result < 2009 || result > 3000) {
                std::cout << "Error: bad input => " << *it << std::endl;
                return false;
            }
        } else if (idx == 1) {
            if (result <= 0 || result > 12) {
                std::cout << "Error: bad input => " << *it << std::endl;
                return false;
            }
        } else if (idx == 2) {
            if (result == 29) {
                int year;
                std::istringstream tmp (*std::prev(it, 2));
                tmp >> year;
                if (!isLeapYear(year))
                std::cout << "Error: not leap year => " << *it << std::endl;
                return false;
            }
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
}

std::list<std::string> BitcoinExchange::parsingData(const std::string& line) const
{
    std::list<std::string> ret;

    ret.push_back(line.substr(0, 4));
    ret.push_back(line.substr(5, 2));
    ret.push_back(line.substr(8, 2));
    size_t lastSpacePos = line.find_last_of(' ');
    ret.push_back(line.substr(lastSpacePos + 1));
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
