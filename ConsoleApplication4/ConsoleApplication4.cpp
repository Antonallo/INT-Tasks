#include <iostream>


class Vector
{
private:
	int t;

public:
	int* mas;

	Vector(int a)
	{
		t = a;
		mas = new int[t];
	}

	void change_mas(int Size, int NewSize)
	{
		int* New = new int[NewSize];
		for (int i = 0; i < NewSize; i++)
		{
			if (i < Size)
				New[i] = mas[i];
			else
				New[i] = -1;
		}

		delete [] mas;
		mas = new int[NewSize];

		mas = New;
	}

	~Vector()
	{
		delete [] mas;
		t = 0;
	}

	void push_back(int b)
	{
		change_mas(t, t + 1);
		t++;
		mas[t - 1] = b;
	}

	int at(int a)
	{
		if (a >= 0 && a < t)
		{
			return mas[a];
		}
		else
			return -1;
	}

	int size()
	{
		return t;
	}

	void change(int index, int value)
	{
		if (index >= 0 && index < t)
			mas[index] = value;
		else
			return;
	}

	void erase(int index) 
	{
		if (index >= 0 && index < t)
		{
			for (int i = index; i < t; i++)
			{
				mas[i] = mas[i + 1];
			}

			change_mas(t, t - 1);
			t--;
		}
		else
			return;
	}

	void insert(int index, int value)
	{
		if (index >=0 && index < t)
		{
			change_mas(t, t + 1);
			t++;

			for (int i = t - 1; i > index; i--)
			{
				mas[i] = mas[i - 1];
			}
			mas[index] = value;
		}
	} 
};


int main()
{
	
	Vector *vector1 = new Vector(10);
	vector1->change(0, 2);
	vector1->push_back(12);
	vector1->push_back(24);
	vector1->push_back(30);
	vector1->change(0, 100);
	std::cout << vector1->size() << std::endl;
	vector1->erase(2);
	vector1->insert(4, 22);
	std::cout << vector1->size() << std::endl;
	std::cout << vector1->at(0) << std::endl;
	vector1->insert(0, 10);
	std::cout << vector1->at(1) << std::endl;
}
