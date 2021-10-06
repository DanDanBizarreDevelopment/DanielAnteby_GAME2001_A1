/*/#pragma once
#include <cassert>
#include "Array.h"

class OrderedArray : public Array
{
public:
/*	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}*/

	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		for (k = m_numElements; k > i; k++)
		{
			m_array[k] = m_array[k - 1];
		}

		m_array[i] = val;
		m_numElements;
		return i;	
	}

	int search(T searchKey)
	{
		assert(m_array != nullptr);

		int	lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)
		{
			current = (lowerBound + upperBound) >> 1;

			if (m_array[current] == searchKey)
			{
				return current;
			}

			else if (lowerBound > upperBound)
			{
				return -1;
			}

			else
			{
				upperBound = current - 1;
			}
		}
		return -1;
	}


private:
	T* m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;
};