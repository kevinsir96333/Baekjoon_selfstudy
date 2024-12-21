#include <cctype>
#include <iostream>
#include <cmath>
int main()
{
    long sum = 0;
    int temp = 0;
    for(int i = 0; i < 5; i++)
    {
        std::cin >> temp;
        sum += std::pow(temp,2); 
    }
    std::cout << sum%10 << std::endl;
    return 0;
}