#include <iostream>
#include <string>



double checker(std::string input)
{
    if(input == "A+")
        return 4.5;
    else if (input == "A0")
        return 4.0;
    else if (input == "B+")
        return 3.5;
    else if (input == "B0")
        return 3.0;
    else if (input == "C+")
        return 2.5;
    else if (input == "C0")
        return 2.0;
    else if (input == "D+")
        return 1.5;
    else if (input == "D0")
        return 1.0;
    else 
        return 0.0;
}



int main()
{
    float credits = 0.0 ;
    auto totalCredits = 0.0;
    double final;

    std::string lec = "";
    double curcredit = 0.0;
    std::string grade = "";
    double gradeCre = 0.0;

    for(int i = 0; i < 20 ; i++)
    {
        std::cin >> lec >> curcredit >> grade;

        if( grade == "P")
            continue;
        
        gradeCre = checker(grade);
        credits += curcredit;
        totalCredits += gradeCre * curcredit;
    }

    if(credits == 0)
    {
        final = 0.0000;
    }

    else 
    {
        final = totalCredits/credits;
    }

    std::cout << final << std::endl;
    
    return 0;
}