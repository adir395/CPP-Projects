#include <iostream>
using namespace std;

template <class T>

class Set
{
private:
	T* arr;
	int size;
public:
	Set();
	Set(T* arr, int size);
	Set(const Set& other);
	~Set();
	const Set operator+(const Set& s) const;
	const Set operator-(const Set& s) const;
	const Set operator*(const Set& s) const;
	Set& operator=(const Set& s);
	bool operator==(const Set& s) const;
	bool in(T element) const;
	void print() const;
};

template <class T>
Set<T>::Set()
{
	size = 0;
	arr = NULL;
}

template <class T>
Set<T>::Set(T* arr, int size)
{
	this->size=size;
	this->arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

template <class T>
Set<T>::Set(const Set& other)
{
	size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template <class T>
Set<T>::~Set()
{
	delete[] arr;
}

template<class T>
const Set<T> Set<T>::operator+(const Set& s) const
{
	int count = size + s.size;
	T* new_arr = NULL;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				count--;
				break;
			}
		}
	}
	new_arr = new T[count];
	int i = 0;
	for (i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	for (int j = 0; j < s.size; j++)
	{
		for (int k = 0; k < count; k++)
		{
			if (s.arr[j]==new_arr[k])
				break;
			if (k == count - 1)
			{
				new_arr[i] = s.arr[j];
				i++;
			}
		}
	}

	Set new_Set(new_arr, count);
	return new_Set;
}

template<class T>
const Set<T> Set<T>::operator-(const Set& s) const
{
	int count = size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				count--;
				break;
			}
		}
	}
	T* new_arr = new T[count];
	int i = 0;
	for (int j = 0; j < size; j++)
	{
		for (int k = 0; k < s.size; k++)
		{
			if (arr[j] == s.arr[k])
				break;
			if (k == s.size - 1)
			{
				new_arr[i] = arr[j];
				i++;
			}
		}
	}
	Set new_set(new_arr, count);
	return new_set;
}

template<class T>
const Set<T> Set<T>::operator*(const Set& s) const
{
	int count = 0,k=0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
				count++;
		}
	}
	T* new_arr = new T[count];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
			{
				new_arr[k] = arr[i];
				k++;
			}
		}
	}
	Set new_set(new_arr, count);
	return new_set;
}

template<class T>
Set<T>& Set<T>::operator=(const Set& s)
{
	size = s.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = s.arr[i];
	return *this;
}

template<class T>
bool Set<T>::operator==(const Set& s) const
{
	if (size != s.size)
		return false;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s.size; j++)
		{
			if (arr[i] == s.arr[j])
				count++;
		}
	}
	if (count == size)
		return true;
	return false;
}

template<class T>
bool Set<T>::in(T element) const
{
	for (int i = 0; i < size; i++)
		if (arr[i] == element)
			return true;
	return false;
}

template<class T>
void Set<T>::print() const
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


