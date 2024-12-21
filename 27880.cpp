#include <iostream>

const int STAIR= 17;
const int ES = 21;

enum class P {
    Es, Stair 
};

int main()
{
    std::string type;
    P typeconv; 
    long num; 
    long sum = 0;
    int t = 4;

    while (0 < t)
    {
        std::cin >> type >> num;
        if(type == "Es")
            typeconv = P::Es;
        else
            typeconv = P::Stair;
        switch (typeconv) 
        {
            case P::Es:
                sum += ES*num;
                break;
            case P::Stair:
                sum+= STAIR*num;
        }
        t--;
    }

    std::cout << sum << std::endl;

    return 0;
}