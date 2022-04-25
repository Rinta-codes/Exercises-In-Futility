/*
The class should be named Stack, and should contain:
* A private fixed array of integers of length 10.
* A private integer to keep track of the length of the stack.
* A public member function named reset() that sets the length to 0.
* A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
* A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
* A public member function named print() that prints all the values in the stack.
*/

#include <iostream>
#include <cassert>

class Stack
{
	static const int stackMaxLength{ 10 };
	int m_array[stackMaxLength];
	int m_length{0};		// stack length

public:

	// A public member function named reset() that sets the length to 0.
	void reset()
	{
		m_length = 0;
	}

	// A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
	bool push(int value)
	{
		if (m_length == stackMaxLength)
			return false;
		else
		{
			m_array[m_length] = value;
			++m_length;
		};

		return true;
	}

	// A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
	int pop()
	{
		assert(m_length > 0 && "Attempted to pop() an empty Stack");

		--m_length;
		return m_array[m_length];
	}

	// A public member function named print() that prints all the values in the stack.
	void print()		// Print format: ( 5 3 8 )
	{
		std::cout << "( ";

		for (int i{ 0 }; i < m_length; ++i)
		{
			std::cout << m_array[i] << " ";
		};

		std::cout << ")\n";
	}
};


int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	// stack.pop();

	stack.print();

	return 0;
}