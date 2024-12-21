#include <iostream>
#include <vector>

struct Cell {
    bool sth = false;
    long num = 0;
    int idx = 0;
};

template<typename T> 
Cell* calEnemy(std::vector<T> arr, long limit)
{

    Cell* resultArr = new Cell[arr.size()];
    for(int i = 0 ; i < arr.size(); i++)
    {
        if(i == 0)
        {
            if(arr[i] + arr[i+1] <= limit && arr[i] + arr[arr.size()] > limit)
            {
                resultArr[i].num = arr[i] + arr[i+1];
                resultArr[i].idx = i + 1;
            }
            else if (arr[i] + arr[arr.size()] <= limit && arr[i] + arr[i +])
            else {
                resultArr[i].num = arr[i];
                resultArr[i].idx = -1;
            }
        }

        else if ( i != arr.size()) 
        {
            if(arr[i-1] + )
        }
    }
}

int main()
{
    int T = 0;
    std::cin >> T;
    while(0 < T--)
    {
        int strict = 0;
        long solNum = 0;
        long temp = 0;
        std::cin >> strict >> solNum;
        std::vector<long> arr;
        for(int i = 0; i < 2 * strict ; i++)
        {
            std::cin >> temp;
            arr.push_back(temp);
        }




    }
}