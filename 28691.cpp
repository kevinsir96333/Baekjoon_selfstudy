#include <iostream>

int main()
{
    std::string input = "";
    std::cin >> input;
    if(input == "M" || input == "m")
        std::cout << "MatKor" << std::endl;
    else if (input == "W" || input == "w")
        std::cout << "WiCys" << std::endl;
    else if (input == "C")
        std::cout << "CyKor" << std::endl;
    else if (input == "A" || input == "a")
        std::cout << "AlKor" << std::endl;
    else if (input == "$")
        std::cout << "$clear" << std::endl;
    
    return 0;
}