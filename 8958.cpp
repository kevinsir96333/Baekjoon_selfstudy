#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main()
{
    int T = 0;
    std::cin >> T;
    while (0 < T)
    {
        std::string input; 
        std::cin >> input;
        std::queue<char> stk; 
        int sum = 0;
        for(auto e : input)
        {
            if(e == 'O')
            {
                stk.push(e);
            }

            else if(e == 'X')
            {
                stk.push('/');
            }
        }

        int tempSum = 0;
        while(!stk.empty())
        {
            auto chr = stk.front();
            if(chr == 'O')
            {
                sum += tempSum;
                tempSum++;
                if(stk.size() == 1)
                    sum += tempSum;
            }    
            else if(chr == '/')
            {
                sum +=tempSum ;
                tempSum = 0;
            }
            stk.pop();
        }
        std::cout << sum << std::endl;
        T--;
    }
    return 0;
}