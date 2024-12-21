#include <iostream>

int main()
{
    long long N, M = 0;
    std::cin >> N >> M;
    if( N == M)
        std::cout << 1 << std::endl;
    else 
        std::cout << 0 << std::endl;
    return 0;
}