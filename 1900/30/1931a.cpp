#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::string s(3, 'a');
    for (size_t i = 2; ~i != 0; --i) {
        const unsigned d = std::min<unsigned>(n - i, 26);
        s[i] += d - 1;
        n -= d;
    }

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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
