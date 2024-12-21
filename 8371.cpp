#include <iostream> 
#include <string>

int main()
{
    int size = 0;
    int count = 0;
    std::cin >> size; 
    std::string str1; 
    std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    //std::getline(std::cin, str1);
    //std::getline(std::cin, str2);
    for(int i = 0; i < size ; i++)
    {
        if(int(str1[i]) != int(str2[i]))
            count++;
    }

    std::cout << count << std::endl;

    return 0; 

}