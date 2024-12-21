#include <iostream>

int main()
{
    int arr1[4];
    int arr2[2];
    int sum = 0;
    int temp1 = 0;
    int opr = 101;

    for(int i = 0; i < 6 ; i++)
    {
        if( i < 4 )
        {
            std::cin >> arr1[i];
            if( arr1[i] < opr) opr = arr1[i];
            sum += arr1[i];
        }
        else
            std::cin >> arr2[i - 4];
            if( i == 4) temp1 = arr2[i-4];
            else if (i == 5) sum += std::max(arr2[i-4], temp1);

        if (i == 3) 
        {
            sum -= opr;
        }

    }

    std::cout << sum << std::endl;

    return 0;
    
}