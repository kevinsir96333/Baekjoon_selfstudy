#include <iostream>
#include <string>

int main()
{
    std::string str = "";
    while( std::getline(std::cin, str) && str != "END")
    {
        for(int i = str.size() - 1; 0 <= i ; i--)
        {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }

    return 0; 
}