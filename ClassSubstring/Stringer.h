#ifndef STRINGER_H_45156271351
#define STRINGER_H_45156271351

#include <string>

class Stringer
{
private:
	std::string m_string;

public:
	Stringer(const std::string &s = "") : m_string{s} {}

	std::string operator() (int index, int length);
};


#endif
