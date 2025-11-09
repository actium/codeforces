#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned r, unsigned x, unsigned d)
{
    unsigned k = 0;
    for (const char c : s) {
        if (c == '1' || c == '2' && r < x)
            ++k;

        if (c == '1' && r >= x)
            r -= std::min(r - (x - 1), d);
    }

    answer(k);
}

void test_case()
{
    unsigned r, x, d;
    std::cin >> r >> x >> d;

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s, r, x, d);
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
