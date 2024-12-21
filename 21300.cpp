#include <iostream>

int main()
{
    int temp = 0;
    long sum = 0;
    for(int i = 0; i < 6; i++)
    {
        std::cin >> temp; 
        sum += temp*5;
    }
    std::cout << sum << std::endl;
    return 0;
}