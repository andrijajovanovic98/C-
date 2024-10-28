#include "BitcoinExchange.hpp"

// Orthodox Form

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->prices = other.prices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->prices = other.prices;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {};


// Member Functions

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    
    std::ifstream file(filename.c_str());
    if(!file)
    {
        std::cerr << "Error: " << filename << " cant be opened." << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file,line)) {
        std::istringstream ss(line);
        std::string date;
        float price;
        if (std::getline(ss, date, ',') && ss >> price)
            prices[date] = price;
        else
            std::cerr << "Incorrect row in the database" << std::endl;
    }
}

float BitcoinExchange::getPrice(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = prices.find(date);
    if (it != prices.end()) 
        return it->second;
    it = prices.lower_bound(date);

    if (it == prices.begin())
    {
        std::cout << "There is no lower date then: " << date << std::endl;
        return prices.begin()->second;
    }
    --it;
    return (it->second);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    for (std::string::size_type i = 0; i < date.size(); i++) {
        if ((i == 4 || i == 7) && date[i] == '-') continue;
        if (!isdigit(date[i])) return false;
    }

 int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    return (true);
}

void    outOfTheRange(float value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
    }
    else
    {
        std::cerr << "Error: too large a number." << std::endl;
    }
}

int validFile(char **argv)
{
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Couldnt open the input file: " << argv[1] << std::endl;
        return (1);
    }
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Empty file" << std::endl;
        return (1);
    }
    std::string line;
    if (std::getline(inputFile, line)) {
        if (line != "date | value") {
            std::cerr << "Invalid input: first line should be: 'date | value'" << std::endl;
            return (1);
        }   
    }
    return (0);
}
int errorHandling(int argc, char **argv) {

    const std::string filename = "data.csv";
    std::ifstream file(filename.c_str());
    if(!file)
    {
        std::cerr << "Error: " << filename << " cant be opened." << std::endl;
        return (1);
    }
    if (argc != 2) {
        std::cerr << "Usage: ./betc <input_file>" << std::endl;
        return (1);
    }
    std::string inputFileName = argv[1];
    if (inputFileName.substr(inputFileName.find_last_of(".") + 1) != "csv") {
        std::cerr << "Error: Only .csv files are allowed." << std::endl;
        return (1);
    }
    if (validFile(argv) == 1)
        return (1);
    return (0);
}

bool checkingCorrectFormat(const std::string& line) {
    size_t pipePos = line.find('|');
    if (pipePos != std::string::npos && line[pipePos - 1] == ' ' && line[pipePos + 1] == ' ') {
        if (line[pipePos - 2] != ' ' && line[pipePos + 2] != ' ') {
            return true;
        }
    }
    return false;
}

int mainLoop(int argc, char **argv)
{
    if (errorHandling(argc, argv) == 1)
        return (1);
    BitcoinExchange exchange("data.csv");
    std::ifstream inputFile(argv[1]);
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        if (checkingCorrectFormat(line)) {
            size_t pipePos = line.find('|');
            std::string date = line.substr(0, pipePos - 1);
            std::string valueStr = line.substr(pipePos + 2);
            std::istringstream valueStream(valueStr);
            float value;
            if (valueStream >> value) {
                if (!exchange.isValidDate(date)) {
                    std::cerr << "Bad input " << date << std::endl;
                    continue;
                }
                if (value < 0 || value > 1000) 
                {
                    outOfTheRange(value);
                    continue;
                }
                float price = exchange.getPrice(date);
                if (price != -1)
                    std::cout << date << " => " << value << " = " << value * price << std::endl;
            } else {
                std::cerr << "Invalid value format: " << valueStr << std::endl;
            }
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;
        }
    }
    return (0);
}
