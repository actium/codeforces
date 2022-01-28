#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n == 4 && k == 3)
        return no_answer();

    const auto c = [n](unsigned x) {
        return x ^ (n - 1);
    };

    std::vector<std::pair<unsigned, unsigned>> p;
    if (k != n - 1) {
        p.emplace_back(0, c(k));
        for (unsigned i = 1; i < n / 2; ++i) {
            if (i == k || i == c(k))
                p.emplace_back(k, n - 1);
            else
                p.emplace_back(i, c(i));
        }
    } else {
        p.emplace_back(0, n / 2);
        p.emplace_back(1, n / 2 - 1);
        p.emplace_back(n - 2, n - 1);
        for (unsigned i = 2; i < n / 2 - 1; ++i)
            p.emplace_back(i, c(i));
    }

    answer(p);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
