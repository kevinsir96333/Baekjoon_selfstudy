#include <iostream>

int main()
{
    int N;
    unsigned long acc = 1;
    std::cin >> N;
    if (N == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    for(auto i = 1; i <= N; i++)
    {
        acc *= i;
    }

    std::cout << acc <<std::endl;
    return 0;
}