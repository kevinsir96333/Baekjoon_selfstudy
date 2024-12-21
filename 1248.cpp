#include <iostream>
#include <string> 

int main()
{
    std::string str; 
    while(std::cin >> str && str != "0") 
    {
        int blank = str.size() - 1;
        int sum = blank; 
        for(auto i : str)
        {
            if(i == '1') 
            {
                sum += 2;
            }
            else if (i == '2')
            {
                sum += 3;
            }
            else if (i == '0')
            {
                sum += 4;
            }
            else 
            {
                sum += 3; 
            }
        }

        sum +=2; 
        std::cout << sum << std::endl;
    }
    return 0;
}