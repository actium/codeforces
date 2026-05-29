#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.size();

    std::vector<unsigned> c(n+1);
    for (size_t i = n; i != 0; --i)
        c[i-1] = c[i] + s[i-1] % 2;

    unsigned k = 0;
    for (size_t i = 0, t = 0; i < n; ++i) {
        t += (s[i] == '2');
        k = std::max<unsigned>(k, t + c[i]);
    }

    answer(n - k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
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
