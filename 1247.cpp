/*
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int testCase = 3;


int main()
{
    std::vector<std::string> res1; 
    while(0 < testCase)
    {
        std::vector<long long> positive;
        std::vector<long long> negative; 
        std::vector<int> zeros;
        int N = 0;
        std::cin >> N;

        long long temp;
        for(int i = 0; i < N ; i++)
        {
            std::cin >> temp; 
            if( 0 < temp)
                positive.push_back(temp);
            else if (temp < 0)
                negative.push_back(temp);
            else
                zeros.push_back(temp);
        }

        if(negative.empty()&&positive.empty())
        {
            res1.push_back("0");
        }
        else if(negative.empty()&&!positive.empty())
        {
            res1.push_back("+");
        }
        else if(!negative.empty()&&positive.empty())
        {
            res1.push_back("-");
        } 
        else 
        {
            std::vector<long long> result;
            int idx1 = 0; 
            int idx2 = 0;
            while( idx1 < positive.size() && idx2 < negative.size())
            { 
                
                result.push_back(positive[idx1] + negative[idx2]);                
                idx1++; idx2++;
            }

            while(idx1 < positive.size())
            {
                result.push_back(positive[idx1]);
                idx1++;
            }

            while(idx2 < negative.size())
            {
                result.push_back(negative[idx2]);
                idx2++;
            }

            long long sum = 0;

            for(auto i : result)
            {
                sum += i;
            }


            if(sum == 0)
            {
                res1.push_back("0");
            }
            else if( 0 < sum)
            {
                res1.push_back("+");
            }
            else if(sum < 0)
            {
                res1.push_back("-");
            } 

        }
        testCase--;
    }

    for(auto i : res1)
    {
        std::cout << i << std::endl;
    }



    return 0;
}
*/


#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cctype>

__int128 stringToInt128(const std::string& s) {
    __int128 num = 0;
    int start = 0;
    bool is_negative = false;

    if (s[0] == '-') {
        is_negative = true;
        start = 1;
    }

    for (size_t i = start; i < s.size(); ++i) {
        if (std::isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
    }

    return is_negative ? -num : num;
}

int main() {

    int testCase = 3;

    while(testCase > 0) {
        int N;
        std::cin >> N;

        __int128 positive_sum = 0;
        __int128 negative_sum = 0;

        for(int i = 0; i < N; ++i) {
            std::string num_str;
            std::cin >> num_str;

            __int128 num = stringToInt128(num_str);

            if(num > 0)
                positive_sum += num;
            else if(num < 0)
                negative_sum += num; 
        }

        if(positive_sum + negative_sum > 0)
            std::cout << "+" << "\n";
        else if(positive_sum + negative_sum < 0)
            std::cout << "-" << "\n";
        else
            std::cout << "0" << "\n";

        testCase--;
    }

    return 0;
}
