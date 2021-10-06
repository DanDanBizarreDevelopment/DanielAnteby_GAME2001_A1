/*#pragma once
#include <cassert>
#include "Array.h"

class UnorderedArray : public Array {

public:
	UnorderedArray(int size, int growBy = 1) :
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

	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	void push(T val)
	{
		assert(m_array != nullptr);

		if(m_numElements >= m_maxSize)
		{
			Expand();
		}

		m_array[m_numElements] = val;
		m_numElements++;
	
	}

	int search(T val)
	{
		assert(m_array != nullptr);

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
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

	