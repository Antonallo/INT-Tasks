#include <iostream>
#include <string>
#include <vector>

using namespace std;


string reverse(string& s)
{
	int n = s.length();
	for (int i = 0; i < n / 2; i++)
		swap(s[i], s[n - i - 1]);
	return s;
}

void zanull(string &c, string &d)
{
	reverse(c);
	reverse(d);
	if (c.size() >= d.size())
	{
		while (c.size() != d.size())
			d.push_back('0');
	}
	else
	{
		while (c.size() != d.size())
			c.push_back('0');
	}
}


void mult (string a, string b)
{
	zanull(a, b);

	vector<int> vector1( 2 * a.size());

	for (int i = 0; i < a.size(); i++)
	{
		int carry = 0;
		for (int j = 0; j < a.size(); j++)
		{
			vector1[i + j] += carry + (a[i] - 48) * (b[j] - 48);
			carry = vector1[i + j] / 10;
			vector1[i + j] %= 10;
		}
		vector1[i + a.size()] += carry;
	}

	while (vector1[vector1.size() - 1] == 0 && vector1.size() != 1)
		vector1.resize(vector1.size() - 1);

	vector1.shrink_to_fit();

	for (int i = vector1.size() - 1; i >= 0; i--)
	{
		{
			cout << vector1[i];
		}		
	}
}


void sum(string a, string b)
{
	zanull(a, b);

	for (int i = 0; i < a.size(); i++)
	{
		a[i] = (a[i] - '0') + (b[i] - '0');
		a[i + 1] = ((a[i + 1] - '0') + (a[i] / 10)) + '0';
		a[i] = (a[i] % 10) + '0';
	}


	if (a[a.size()] == 1)
		a[a.size()] += '0';


	for (int i = a.size(); i >= 0; i--)
		cout << (a[i]);
}

int main()
{
	string t, n;
	cin >> t >> n;
	sum(t, n);
	cout << endl;
	mult(t, n);
}
