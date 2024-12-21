#include <iostream>
#include <string> 

int main()
{
    int T; 
    std::cin >> T; 
    while (0 < T)
    {
        int count = 0;
        int str2Cnt = 0;
        std::string str1;
        std::string str2;

        std::cin >> str1;
        std::cin >> str2; 

        for(int i = 0 ; i < str1.size(); i++)
        {
            if(str1[i] != str2[i])
            {
                count++;
            }

            str2Cnt++;
        }

        while(str2Cnt != str2.size())
        {
            count++;
            str2Cnt++;
        }

        T--;
        std::cout << "Hamming distance is " << count << "." << std::endl;
    }

    return 0;
}