#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool check(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    for (size_t r = 1; r < n; ++r) {
        for (size_t l = 0; l < r; ++l) {
            unsigned s = 0;
            for (size_t i = l; i <= r; ++i)
                s += p[i];

            if (s % (r - l + 1) == 0)
                return false;
        }
    }
    return true;
}

void solve(unsigned n)
{
    if (n == 1)
        return answer({1});

    if (n % 2 == 1)
        return no_answer();

    std::vector<unsigned> p(n);
    for (unsigned i = 0; i < n; i += 2) {
        p[i] = i + 2;
        p[i+1] = i + 1;
    }
    answer(p);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
