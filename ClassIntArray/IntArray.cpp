#include <cassert>
#include "IntArray.h"

int& IntArray::operator[](int index)
{
	assert(index >= 0 && index < m_size && "IntArray index out of bounds for operator[]");
	
	return m_array[index];
}

std::ostream& operator<< (std::ostream &out, const IntArray &array)
{
	if (!array.m_size)
		out << "The array is empty";
	else
		for (int value{ 0 }; value < array.m_size; value++)
			out << array.m_array[value] << ' ';

	return out;
}

IntArray::IntArray(const IntArray &array)
{
	m_size = array.m_size;

	if (!m_size)
		m_array = nullptr;
	else
		m_array = new int[m_size] { 0 };

	for (int value = 0; value < m_size; value++)
		m_array[value] = array.m_array[value];
}

IntArray& IntArray::operator= (const IntArray &array)
{
	if (&array == this)
		return *this;

	m_size = array.m_size;

	delete[] m_array;

	if (!m_size)
		m_array = nullptr;
	else
		m_array = new int[m_size] { 0 };

	for (int value = 0; value < m_size; value++)
		m_array[value] = array.m_array[value];
}
