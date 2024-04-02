#include <iostream>
#include <vector>

using integer = unsigned long long;

std::vector<std::vector<integer>> t;

void initialize()
{
    for (integer x = 1; x <= 1000000; ) {
        const size_t k = t.empty() ? 0 : t.back().size();

        for (t.emplace_back(); t.back().size() <= k; ++x) {
            t.back().push_back(x * x);

            const size_t j = t.back().size() - 1;
            if (j != 0)
                t.back()[j] += t.end()[-2][j-1];
        }
    }
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned r = 1;
    while (r * (r + 1) / 2 < n)
        ++r;

    const unsigned c = n - (r - 1) * r / 2 - 1;

    integer s = 0;
    while (r-- != 0 && c < t[r].size())
        s += t[r][c];

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
