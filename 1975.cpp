#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

static int bigCompare(const std::string &a, const std::string &b)
{
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return 1;
    return a.compare(b);
}

static std::string bigAdd(const std::string &a, const std::string &b)
{
    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    std::string r;

    while (i >= 0 || j >= 0 || carry) {
        int x = 0;
        int y = 0;
        if (i >= 0) {
            x = a[i] - '0';
            i--;
        }
        if (j >= 0) {
            y = b[j] - '0';
            j--;
        }
        int s = x + y + carry;
        carry = s / 10;
        r.push_back((char)((s % 10) + '0'));
    }
    std::reverse(r.begin(), r.end());
    return r;
}

static std::string bigMul(const std::string &a, int b)
{
    if (a == "0" || b == 0) {
        return "0";
    }
    int carry = 0;
    std::string r;

    int i = (int)a.size() - 1;
    for (; i >= 0; i--) {
        int x = a[i] - '0';
        long long m = (long long)x * (long long)b + (long long)carry;
        carry = (int)(m / 10);
        r.push_back((char)((m % 10) + '0'));
    }
    while (carry > 0) {
        r.push_back((char)((carry % 10) + '0'));
        carry /= 10;
    }
    std::reverse(r.begin(), r.end());
    return r;
}

static std::string bigSub(const std::string &a, const std::string &b)
{
    if (b == "0") {
        return a;
    }
    if (a == b) {
        return "0";
    }
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    std::string r;

    while (i >= 0 || j >= 0) {
        int x = 0;
        int y = 0;
        if (i >= 0) {
            x = a[i] - '0';
            i--;
        }
        if (j >= 0) {
            y = b[j] - '0';
            j--;
        }
        x -= carry;
        if (x < y) {
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        int d = x - y;
        r.push_back((char)(d + '0'));
    }
    while (r.size() > 1 && r.back() == '0') {
        r.pop_back();
    }
    std::reverse(r.begin(), r.end());
    return r;
}

static std::vector< std::pair<long long,int> > primeFactorization(long long n)
{
    std::vector< std::pair<long long,int> > r;
    int c = 0;
    while (n % 2 == 0) {
        n /= 2;
        c++;
    }
    if (c > 0) {
        r.push_back(std::make_pair(2LL, c));
    }
    long long i = 3;
    while (i * i <= n) {
        if (n % i == 0) {
            int cc = 0;
            while (n % i == 0) {
                n /= i;
                cc++;
            }
            r.push_back(std::make_pair(i, cc));
        }
        i += 2;
    }
    if (n > 1) {
        r.push_back(std::make_pair(n, 1));
    }
    return r;
}

static std::string solveSingle(long long N)
{
    if (N == 1) {
        return "0";
    }
    std::vector< std::pair<long long,int> > f = primeFactorization(N);
    int sz = (int)f.size();
    std::vector<int> e;
    e.reserve(sz);

    int M = 0;
    for (int idx = 0; idx < sz; idx++) {
        e.push_back(f[idx].second);
        if (f[idx].second > M) {
            M = f[idx].second;
        }
    }

    std::string ans = "0";
    for (int t = 1; t <= M; t++) {
        std::string p = "1";
        for (int idx = 0; idx < sz; idx++) {
            int a_i = e[idx];
            int val = a_i / t;
            if (val != 0) {
                p = bigMul(p, val + 1);
            }
        }
        if (p == "0") {
            continue;
        }
        if (p == "1") {
            p = "0";
        } else {
            p = bigSub(p, "1");
        }
        if (p != "0") {
            ans = bigAdd(ans, p);
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;
        std::cout << solveSingle(N) << "\n";
    }
    return 0;
}
