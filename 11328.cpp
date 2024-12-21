#include <iostream> 
#include <string> 
#include <algorithm> 

int main()
{
    int testCase = 0; 
    std::cin >> testCase; 
    while( 0 < testCase)
    {
        std::string a,b; 
        std::cin>> a >> b;
        if(a.size() != b.size())
        {
            std::cout << "Impossible" << std::endl;
            continue;
        }
        
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        for(int i = 0 ; i < a.size() ; i++)
        {
            if(a[i]!=b[i])
            {
                std::cout<< "Impossible" << std::endl;
                break;
            }
            else {
                if( i + 1 == a.size())
                    std::cout << "Possible" << std::endl;
            }
        }

        testCase--; 
    }
    return 0;
}
