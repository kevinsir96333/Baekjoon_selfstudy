#include <iostream>
#include <string>

int main()
{
    std::string A,B,C;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cout << std::stoi(A) + stoi(B) - stoi(C) << std::endl;
    std::cout << std::stoi(A+B) - stoi(C) << std::endl;
    return 0;
}