#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include <iterator>
#include <iomanip>


class BitcoinExchange {
private:
    std::string inputFilePath;
    std::map<std::string, double> csvData;
    std::map<std::string, double> inputData;
    
    std::list<std::string> parsingData(const std::string& line) const;
    bool isValidData(std::list<std::string>& input) const;
    double findTargetValue(const std::string& date);
    void setFile();
    void calAndPrint();
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &BitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange& BitcoinExchange);
public:
    BitcoinExchange(char *input);
    ~BitcoinExchange();
    class CanNotOpenFile : public std::exception
    {
        const char* what() const throw();
    };
};
