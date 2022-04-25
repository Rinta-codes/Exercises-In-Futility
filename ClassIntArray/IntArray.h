#ifndef INTARRAY_H_2352126272623
#define INTARRAY_H_2352126272623

#include <cassert>
#include <iostream>

class IntArray
{
private:
	int m_size;
	int *m_array;

public:
	IntArray(int size = 0) : m_size{ size }
	{
		assert(size >= 0 && "Cannot create IntArray of negative size");

		if (!size)
			m_array = nullptr;
		else
			m_array = new int[size] { 0 };
	}

	IntArray(const IntArray &array);

	IntArray& operator= (const IntArray &array);

	int& operator[](int index);

	friend std::ostream& operator<< (std::ostream &out, const IntArray &array);

	~IntArray()
	{
		delete[] m_array;
	}
};


#endif