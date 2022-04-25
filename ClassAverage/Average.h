#ifndef AVERAGE_H_246123412456
#define AVERAGE_H_246123412456

#include <stdint.h>
#include <iostream>

class Average
{
private:
	int32_t m_total;
	int8_t m_count;

public:
	Average() :
		m_total{ 0 }, m_count{ 0 }
	{}

	friend std::ostream& operator<< (std::ostream &out, const Average &avg);

	Average& operator+= (int value);
};



#endif