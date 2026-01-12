#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& r)
{
    const size_t n = r.length();

    unsigned k = 0;

    const auto fix = [&](size_t x) {
        if (r[x] == 'u') {
            r[x] = 's';
            ++k;
        }
    };

    fix(0);
    for (size_t i = 1; i < n; ++i) {
        if (r[i-1] == 'u')
            fix(i);
    }
    fix(n-1);

    answer(k);
}

void test_case()
{
    std::string r;
    std::cin >> r;

    solve(r);
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
