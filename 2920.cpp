#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ascending = {1,2,3,4,5,6,7,8};
    std::vector<int> descending = {8,7,6,5,4,3,2,1};
    int count_ascending = 0;
    int count_descending = 0;

    int temp = 0;

    for(int i = 0; i < 8 ; i++)
    {
        std::cin >> temp;
        if(temp == ascending[i])
            count_ascending++;
        else if (temp == descending[i])
            count_descending++;
    }

    if(count_ascending == 8)
        std::cout << "ascending" << std::endl;
    else if (count_descending == 8)
        std::cout << "descending" << std::endl;
    else
        std::cout << "mixed" << std::endl;
    
    return 0;
}