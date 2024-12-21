#include <iostream>


int main()
{
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n ; i++)
    {
        int X,Y;
        std::cin >> X >> Y; 
        if( X < Y) 
            std::cout << "NO BRAINS" << std::endl;
        else 
            std::cout << "MMM BRAINS" << std::endl;
    }

    return 0;
}