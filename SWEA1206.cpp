#include <iostream>


struct Node{
    Node* next;
    Node* prev;
}; 


void array_clear(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main() {
    int n = 0; int i =0 ; int temp = 0; 
    int acc = 0;
    std::cout << "Start" << std::endl; 
    for(int t = 0; t < 10; t++)
    {
        std::cin >> n;
        int* vectorArr = new int[n];
        int* clearArr = new int[n];
        for(int j = 0; j < n ; j++)
        {
            std::cin >> temp ;
            vectorArr[j] = temp;
        }
        for(int i = 0 ; i < n ; i++) {
            if(vectorArr[i] == 0) {
                clearArr[i] = 0;
                if(n-2 <= i) break; 
                continue;
            }
            else{

                if( 2 <= i  && i <= n- 3)
                {
                    clearArr[i] = vectorArr[i] - std::max(std::max(vectorArr[i-1], vectorArr[i+1]), std::max(vectorArr[i-2], vectorArr[i+2]));
                }
                if(clearArr[i] < 0) clearArr[i] = 0;
                acc += clearArr[i];
            }
        }


        std::cout << "#" << t << " " << acc << std::endl;

        array_clear(vectorArr, n);
        array_clear(clearArr, n);
        acc = 0;
    }
}