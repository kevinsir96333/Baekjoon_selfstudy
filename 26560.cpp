#include <iostream>
#include <string>



int main()
{
    int T;
    std::cin >> T;
    bool switch1 = false;
    while(T)
    {
        std::string input = "";

        std::getline(std::cin, input);

        if(input != "" &&input[input.size()-1] != '.')
        {
            input.append(".");
        }

        if(input != "")
        {
            std::cout << input << std::endl;
            T--;
        }
    }
    return 0;
}

