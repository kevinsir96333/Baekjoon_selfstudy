#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

int main()
{
    int T; 
    std::cin >> T;
    while(0 < T)
    {
        int temp; 
        int sum = 0;
        std::vector<int> score;
        for(int i = 0; i < 5; i++)
        {
            std::cin >> temp; 
            score.push_back(temp); 
        }
        std::sort(score.begin(), score.end());
        if(abs(score[1] - score[3]) >= 4)
        {
            std::cout << "KIN" << std::endl; 
            T--;
            continue;
        }

        for(int i = 1; i < 4; i++)
        {
            sum += score[i];
        }

        std::cout << sum << std::endl; 
        T--; 
    }
    
    return 0;
}