#include <iostream>
#include <cstddef>

int main()
{
	unsigned char n1 = 0b1000;
	unsigned char n2 = 0b111;
	unsigned char x = (n1 << 4) | n2;
	unsigned char r1 = (x & 0b11110000) >> 4;
	unsigned char r2 = (x & 0b00001111);
	std::cout << int(r1) << int(r2) << int(x);
}
