#include <iostream>
#include <string>
#include <algorithm>

int compareAbs(const std::string &a, const std::string &b) {
    if (a.size() < b.size()) return -1;
    else if (a.size() > b.size()) return 1;
    else {
        if (a < b) return -1;
        else if (a > b) return 1;
        else return 0;
    }
}

std::string addBigIntegers(const std::string &a, const std::string &b) {
    std::string result;
    int carry = 0, sum = 0;
    int i = (int)a.size() - 1, j = (int)b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtractBigIntegers(const std::string &a, const std::string &b) {
    std::string result;
    int borrow = 0, diff = 0;
    int i = (int)a.size() - 1, j = (int)b.size() - 1;

    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;
        y += borrow;

        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff = x - y;
        result.push_back(diff + '0');
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string multiplyBigIntegers(const std::string &a, const std::string &b) {
    int m = (int)a.size(), n = (int)b.size();
    std::string result(m + n, '0');

    for (int i = m - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = n - 1; j >= 0; --j) {
            int product = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    size_t startPos = result.find_first_not_of('0');
    if (startPos == std::string::npos) return "0";
    return result.substr(startPos);
}

std::string addWithSign(const std::string &A, bool aNegative, const std::string &B, bool bNegative) {
    if (aNegative == bNegative) {
        std::string absSum = addBigIntegers(A, B);
        if (aNegative) return "-" + absSum;
        return absSum; 
    } else {
        int cmp = compareAbs(A, B);
        if (cmp == 0) {
            return "0";
        } else if (cmp > 0) {
            std::string absDiff = subtractBigIntegers(A, B);
            return aNegative ? "-" + absDiff : absDiff;
        } else {
            std::string absDiff = subtractBigIntegers(B, A);
            return bNegative ? "-" + absDiff : absDiff;
        }
    }
}

std::string subtractWithSign(const std::string &A, bool aNegative, const std::string &B, bool bNegative) {
    return addWithSign(A, aNegative, B, !bNegative);
}

std::string multiplyWithSign(const std::string &A, bool aNegative, const std::string &B, bool bNegative) {
    if (A == "0" || B == "0") return "0";
    std::string absProduct = multiplyBigIntegers(A, B);
    if (aNegative != bNegative) return "-" + absProduct;
    return absProduct;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    bool aNegative = (a[0] == '-');
    bool bNegative = (b[0] == '-');

    if (aNegative) a = a.substr(1);
    if (bNegative) b = b.substr(1);

    std::string sum = addWithSign(a, aNegative, b, bNegative);
    std::string diff = subtractWithSign(a, aNegative, b, bNegative);
    std::string product = multiplyWithSign(a, aNegative, b, bNegative);

    std::cout << sum << "\n" << diff << "\n" << product << "\n";

    return 0;
}
