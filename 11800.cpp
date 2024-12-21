#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::map<int, std::string> DICE = {
    {1, "Yakk"}, {2, "Doh"}, {3, "Seh"},
    {4, "Ghar"}, {5, "Bang"}, {6, "Sheesh"}
};

int main()
{
    int T; 
    std::cin >> T; 

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int A,B;
        std::cin >> A >> B; 
        int high = std::max(A,B);
        int low = std::min(A,B);

        std::cout << "Case " << caseNum << ": ";

        if (A == B) {
            switch (A) {
                case 1: std::cout << "Habb Yakk" << std::endl; break;
                case 2: std::cout << "Dobara" << std::endl; break;
                case 3: std::cout << "Dousa" << std::endl; break;
                case 4: std::cout << "Dorgy" << std::endl; break;
                case 5: std::cout << "Dabash" << std::endl; break;
                case 6: std::cout << "Dosh" << std::endl; break;
            }
        }
        else {
            if ( (high == 6 && low == 5) ) {
                std::cout << "Sheesh Beesh" << std::endl;
            } else {
                std::cout << DICE.at(high) << " " << DICE.at(low) << std::endl;
            }
        }
    }

    return 0; 
}
