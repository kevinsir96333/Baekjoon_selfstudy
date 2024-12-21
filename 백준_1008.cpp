#include <iostream>
#include <cstdio>

int main()
{
    double A, B;
    std::cin >> A >> B;
    auto res = A/B;
    printf("%.20f", res);

    return 0;
}