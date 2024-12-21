#include <algorithm>
#include <iostream>
#include <vector>

int main()
{   
    std::vector<int> arr;
    int temp = 0;
    for(int i = 0; i < 3; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }
    std::sort(arr.begin(), arr.end());
    std::cout << arr[1] << std::endl;
    return 0;
    
}