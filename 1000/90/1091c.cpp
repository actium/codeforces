#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    const auto c = [](unsigned n, unsigned d) {
        return n * (2 + 1ull * d * n - d) / 2;
    };

    std::vector<integer> f;
    for (unsigned k = 1; k * k <= n; ++k) {
        if (n % k != 0)
            continue;

        f.push_back(c(n / k, k));

        if (n / k != k)
            f.push_back(c(k, n / k));
    }

    std::sort(f.begin(), f.end());

    answer(f);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
