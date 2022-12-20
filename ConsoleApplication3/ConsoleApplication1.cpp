#include <iostream>
#include <bitset>
std::bitset<8> compression(unsigned int a, unsigned int b)
{
    std::bitset<8> b1(a);
    std::bitset<8> b2(b);
    std::bitset<8> b3 = (b1 << 4) | b2;
    return b3;
}

void extraction(std::bitset<8> a)
{
    unsigned int b = (a >> 4).to_ulong();
    unsigned int c = ((a << 4) >> 4).to_ulong();
    std::cout << b << std::endl;
    std::cout << c;
}
int main()
{
    int a = 5;
    int b = 10;
    std::cout <<compression(a, b) << std::endl;
    extraction(compression(a, b));
}
