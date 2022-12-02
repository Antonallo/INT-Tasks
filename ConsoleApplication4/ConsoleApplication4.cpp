#include <iostream>


class Vector
{
private:
	int t;

public:
	int* mas = new int[t];

	Vector(int a)
	{
		t = a;
	}

	~Vector()
	{
		delete[] mas;
	}

	int value(int a)
	{
		return mas[a];
	}

	void push_back(int b)
	{	
		for (int i = 0; i < t - 1; i++)
			mas[i] = mas[i + 1];

		mas[t - 1] = b;
	}
};


int main()
{	
	Vector* vector1 = new Vector (9);
	vector1->push_back(222);
	std::cout << vector1->value(8);
}
