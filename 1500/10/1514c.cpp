#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> s = { 1 };
    {
        unsigned r = 1;
        for (unsigned i = 2; i < n; ++i) {
            if (std::gcd(i, n) == 1) {
                s.push_back(i);
                r = 1ull * r * i % n;
            }
        }

        if (r != 1)
            s.erase(std::find(s.begin(), s.end(), r));
    }
    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
