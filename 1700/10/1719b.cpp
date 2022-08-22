#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (k % 4 == 0)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> v(n / 2);
    for (size_t i = 0; i < n / 2; ++i) {
        if (k % 2 == 1 || i % 2 == 1) {
            v[i].first = 1 + i * 2;
            v[i].second = 2 + i * 2;
        } else {
            v[i].first = 2 + i * 2;
            v[i].second = 1 + i * 2;
        }
    }

    answer(v);
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
