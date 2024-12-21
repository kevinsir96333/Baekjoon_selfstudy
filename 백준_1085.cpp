#include <iostream>


int main()
{   
    int w,h,x,y;
    int temp1, temp2, temp3; 
    std::cin >> x >> y >> w >> h;

    temp1 = w-x;
    temp2 = h-y;

    std::cout << std::min(std::min(temp1,temp2),std::min(x,y)) << std::endl;
    return 0;

}