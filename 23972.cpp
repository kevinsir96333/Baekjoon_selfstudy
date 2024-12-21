#include <iostream>
#include <cmath>

int main() {
    long long K, N;
    std::cin >> K >> N;

    if (N <= 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long numerator = K * N;
    long long denominator = N - 1;
    long long X = (numerator + denominator - 1) / denominator;

    std::cout << X << std::endl;

    return 0;
}
