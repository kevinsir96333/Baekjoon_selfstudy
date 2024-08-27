#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<int> alpha_v(26, 0);

    for(int i = 0; i < str.size(); i++)
    {
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
            alpha_v[str[i] - 'a']++;
            continue;
        }

        alpha_v[str[i] - 'a']++;
    }

    int max_alpha = *max_element(alpha_v.begin(), alpha_v.end());
    int max_alpha_count = count(alpha_v.begin(), alpha_v.end(), max_alpha);

    if(max_alpha_count != 1)
    {
        std::cout << "?" << std::endl;
        return 0;
    }

    std::cout << (char)(max_element(alpha_v.begin(), alpha_v.end()) - alpha_v.begin() + 'A') << std::endl;
    return 0;


}