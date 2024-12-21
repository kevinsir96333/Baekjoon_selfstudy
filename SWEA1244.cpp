#include <iostream>

static int count = 0; 


void quick_sort(int* arr, int size) {
    for(int i = size - 1; 0 < size ; i--)
    {
        int key = arr[i];
        int temp_idx = i;
        if(count == 0) break;

        for(int j = i - 1; 0 < j ; j--)
        {
            if(key < arr[j])
            {
                key = arr[j];
                temp_idx = j;
            }
        }
        if(arr[temp_idx] == arr[size-1-i]) continue;
        int temp = arr[size - 1 - i];
        arr[size -1 - i] = key; 
        arr[temp_idx] = temp;
        count--;

        std::cout << count << std::endl;
        for(int i = 0; i < size; i++)
        {
            std::cout << arr[i];
        }

        std::cout<< std::endl;
    }
}


int main(){
    int test_case = 0; int n = 0; std::string input = "";
    std::cin >> test_case;
    
    for(int i = 0; i < test_case; i++)
    {
        std::cin >> input >> n;
        count = n;
        int* arr = new int[input.size()];
        for(int i = 0; i < input.size(); i++)
        {
            arr[i] = input[i] - '0';
        }

        quick_sort(arr, input.size());

        std::cout << "#" << i << " ";
        for(int i = 0; i < input.size(); i++)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
        count = 0;
    }
}