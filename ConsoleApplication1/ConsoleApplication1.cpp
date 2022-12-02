#include <iostream>
using namespace std;

int main()
{
	int a = 1000;
	int length_of_sum = 1001;
	int length_of_mult = 2001;

	int masA[1000];
	int masB[1000];
	int* masC = new int[length_of_sum];
	int* masD = new int[length_of_mult];

	int t1 = 0;
	int t2 = 0;

	unsigned long long A, B;
	std::cin >> A >> B;

	while (A > 0)
	{
		masA[t1] = A % 10;
		A = A / 10;
		t1++;
	}

	for (int i = t1; i < a; i++)
		masA[i] = 0;

	while (B > 0)
	{
		masB[t2] = B % 10;
		B = B / 10;
		t2++;
	}

	for (int i = t2; i < a; i++)
		masB[i] = 0;


	for (int i = 0; i < length_of_sum; i++)
		masC[i] = 0;

	for (int i = 0; i < length_of_mult; i++)
		masD[i] = 0;

	for (int i = 0; i < length_of_sum; i++)
	{
		masC[i] += masA[i] + masB[i];
		masC[i + 1] += (masC[i] / 10);
		masC[i] %= 10;

	}

	while (masC[length_of_sum - 1] == 0)
	{
		length_of_sum--;
	}

	for (int i = length_of_sum - 1; i >= 0; i--)
		std::cout << masC[i];




	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			masD[i + j] += masA[i] * masB[j];

	for (int i = 0; i < length_of_mult; i++)
	{
		masD[i + 1] += masD[i] / 10;
		masD[i] %= 10;
	}

	while (masD[length_of_mult - 1] == 0)
		length_of_mult--;

	std::cout << std::endl;

	for (int i = length_of_mult - 1; i >= 0; i--)
		std::cout << masD[i];
}