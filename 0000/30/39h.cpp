#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::vector<std::string>>& v)
{
    for (const auto& r : v) {
        const char* separator = "";
        for (const std::string& x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

std::string v(unsigned x, unsigned k)
{
    std::string s;
    if (x >= k)
        s = v(x / k, k);

    s.push_back('0' + x % k);
    return s;
}

void solve(unsigned k)
{
    const size_t n = k - 1;

    std::vector<std::vector<std::string>> t(n, std::vector<std::string>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            t[i][j] = v((i + 1) * (j + 1), k);
    }

    answer(t);
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}

