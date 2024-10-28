#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


class BitcoinExchange {
private:

	std::map<std::string, float> prices;

public:
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange(const std::string& filename);
	float getPrice(const std::string& date) const;
	bool isValidDate(const std::string& date) const;


};

int mainLoop(int argc, char **argv);

#endif