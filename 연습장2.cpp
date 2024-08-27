#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str; 
    //std::pair<char, int> p;
    std::vector

    std::vector<std::pair<int, char>> v;
    for(int i = 0; i< str.size(); i++)
    {
        if( i == 0)
        {
            v.push_back({1, str[i]});
            continue;
        }

        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }


        std::pair<int, char> temp = {1, str[i]};

        if(find(v.begin(), v.end(), temp) == v.end())
        {
            v.push_back({1, str[i]});
        }

        else
        {
            for(int j = 0; j < v.size(); j++)
            {
                if(v[j].second == str[i])
                {
                    v[j].first++;
                }
            }
        }
    }

    sort(v.begin(), v.end());

    if(v[v.size()-1].first == v[v.size()-2].first)
    {
        std::cout << "?" << std::endl;
        return 0;
    }
    char temp2 = toupper(v[v.size()-1].second);
    std::cout << temp2 << std::endl;

    return 0;
/*
    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0)
        {
            p = v[i];
        }
        
        if(p.second < v[i].second)
        {
            p = v[i];
        }

        else if(p.second == v[i].second && p.first != v[i].first)
        {
            p = std::pair<char, int> ('?', p.second);
        }
    }
*/
    //char temp2 = toupper(p.first);
    //std::cout << temp2 << std::endl;
    //return 0;
}