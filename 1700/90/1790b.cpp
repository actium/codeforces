#include <iostream>
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

void solve(unsigned n, unsigned s, unsigned r)
{
    std::vector<unsigned> a(n, s - r);
    for (unsigned i = 1, t = n * (s - r); t > s; ++i) {
        const unsigned d = std::min(t - s, a[i] - 1);
        a[i] -= d;
        t -= d;
    }

    answer(a);
}

void test_case()
{
    unsigned n, s, r;
    std::cin >> n >> s >> r;

    solve(n, s, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
