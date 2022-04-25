#include "IntArray.h"

IntArray& IntArray::operator= (const std::initializer_list<int> &list)
{
	int list_length{ static_cast<int>(list.size()) };

	if (m_length != list_length)
	{
		delete[] m_data;
		m_length = list_length;
		m_data = new int[list_length];
	}

	int count = 0;
	for (auto &element : list)
	{
		m_data[count] = element;
		++count;
	}

	return *this;
}