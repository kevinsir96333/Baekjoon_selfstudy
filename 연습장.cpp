#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> std::ws;
    std::getline(std::cin, str);
    
    int count = 0;
    bool inWord = false;

    for(int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);

        if(str[i] != ' ')
        {
            if(!inWord)
            {
                count++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
