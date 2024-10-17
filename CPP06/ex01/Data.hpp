#ifndef DATA_HPP
#define DATA_HPP

class Data {
private:

	int value;

public:

	Data();
	Data(const Data &other);
	Data& operator=(const Data &other);
	~Data();

	void	setValue(int num);
	int		getValue();

};

#endif