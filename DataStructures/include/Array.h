#pragma once

#include <stdexcept>

namespace DataStructures
{
	template<class Datatype>
	class TArray
	{
	public:
		explicit TArray(int size)
			: m_Array(new Datatype[size])
			, m_Size(size)
		{ }

		~TArray()
		{
			delete[] m_Array;
		}

		// Copy constructor
		TArray(const TArray& other)
			: m_Array(new Datatype[other.size])
			, m_Size(other.size)
		{
			for (int index = 0; index < m_Size; i++)
			{
				m_Array[index] = other[index];
			}
		}

		//Copy assignment
		TArray& operator= (const TArray& other)
		{
			if (this != &other)
			{
				delete[] m_Array;
				m_Size = other.m_Size;
				m_Array = new Datatype[m_Size];

				for (int index = 0; index < m_Size; i++)
				{
					m_Array[index] = other[index];
				}
			}

			return *this;
		}
		void Insert(int item, int index)
		{
			if (index <= 0 || index >= m_Size)
				throw std::out_of_range("Insert index out of range");

			for (int i = m_Size - 1; i > index; i--)
			{
				m_Array[i] = m_Array[i - 1];
			}

			m_Array[index] = item;
		}

		void Remove(int index)
		{
			if (index <= 0 || index >= m_Size)
				throw std::out_of_range("Insert index out of range");

			for (int i = index + 1; i < m_Size; i++)
			{
				m_Array[i - 1] = m_Array[i];
			}
		}
		void Resize(int size)
		{
			Datatype* newArray = new Datatype[size];

			int min;

			// Determine the number of elements to copy (the smaller of OLD and NEW sizes)
			min = (size < m_Size) ? size : m_Size;

			for (int index = 0; index < min; index++)
			{
				newArray[index] = m_Array[index];
			}

			m_Size = size;

			delete[] m_Array;

			m_Array = newArray;
		}

		int Size()
		{
			return m_Size;
		}

		/* Access Operator
		*  Example: TArray<int> intArray(10);
		*			intArray[5] = 42;
		*/
		Datatype& operator[] (int index)
		{
			if (index <= 0 || index >= m_Size)
				throw std::out_of_range("Insert index out of range");

			return m_Array[index];
		}

		/* Access Operator
		*  Example: void Process(int* arrayPointer)
		*			TArray<int> intArray(10)
		*			Process(intArray)
		*/
		operator Datatype* ()
		{
			return m_Array;
		}

	private:
		Datatype*	m_Array;
		int			m_Size;
	};
}