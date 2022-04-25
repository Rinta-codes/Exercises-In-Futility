#include <string>
#include <cassert>
#include "Stringer.h"

std::string Stringer::operator() (int index, int length)
{
	assert("Checking bounds for function Stringer()..." && index >= 0 && length >= 0 && (index + length) < static_cast<int>(m_string.length()));

	std::string temp{};

	for (int i{ index }; i < index + length; i++)
	{
		temp += m_string[static_cast<std::string::size_type>(i)];
	}

	return temp;
}