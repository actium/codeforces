#include <iostream>
#include <vector>

#include <cmath>

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

void solve(unsigned n)
{
    std::vector<unsigned> p(n + 1);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1 + i;

    unsigned long long s = 0;
    for (size_t i = 0; i < n; ++i) {
        s += p[i];

        const unsigned long long r = sqrt(s);
        if (r * r == s) {
            s -= p[i];
            std::swap(p[i], p[i+1]);
            s += p[i];
        }
    }

    if (p.back() == 0) {
        p.pop_back();
        return answer(p);
    }

    no_answer();
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
