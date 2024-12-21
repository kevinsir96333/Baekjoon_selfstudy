#include <iostream>
#include <stack>
#include <string> 

int main()
{
    std::string str; 
    std::stack<char> empStk;
    while (std::getline(std::cin, str))
    {
        if(str == "***")
        {
            break;
        }
        
        std::string result = "";

        for(auto i : str)
        {
            empStk.push(i);
        }

        while(!empStk.empty())
        {
            result.push_back(empStk.top());
            empStk.pop();
        }   
        std::cout << result << std::endl; 
    }

    return 0;
}