#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(size_t n)
{
    constexpr char t[] = { 'a', 'e', 'i', 'o', 'u' };

    std::string s;
    for (size_t i = 0; i < 5; ++i) {
        const size_t k = 5 - i, q = (n - s.length() + k - 1) / k;
        s.append(q, t[i]);
    }

    answer(s);
}

void test_case()
{
    size_t n;
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
