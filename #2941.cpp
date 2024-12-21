//#2941

/*
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 
단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

### 다시풀 것. 


*/

#include <cstddef>
#include <iostream>
#include <string>
#include <stack>

int main()
{
    int count = 0; 
    std::string str;
    std::cin >> str;
    std::stack<char> s;
    std::stack<char> prev;

    for(int i = 0; i < str.size(); i++)
    {
        if(s.empty())
        {
            s.push(str[i]);
        }

        else
        {
            if(s.top() == 'c' && (str[i] == '=' || str[i] == '-') && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 'd' && str[i] == '-' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 'd' && str[i] == 'z' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 'l' && str[i] == 'j' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 'n' && str[i] == 'j' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 's' && str[i] == '=' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else if(s.top() == 'z' && str[i] == '=' && prev.empty())
            {
                s.pop();
                prev.push(str[i]);
                count++;
            }

            else
            {
                s.push(str[i]);
                if(!prev.empty())
                    prev.pop();
            }
        }
        
    }

    while(true)
    {
        if(s.empty())
        {
            break;
        }

        if(s.top() != '=' && s.top() != '-')
        {
            count++;
        }

        s.pop();
    }

    std::cout << count << std::endl;

    return 0;
}