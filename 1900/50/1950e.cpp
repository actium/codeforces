#include <iostream>
#include <string>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto check = [&](const std::string& p) {
        const size_t k = p.length();

        unsigned d = 0;
        for (size_t i = 0; i < k; ++i) {
            for (size_t j = i; j < n; j += k)
                d += (s[j] != p[i]);
        }
        return d < 2;
    };

    size_t k = n;
    for (size_t i = 1; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        if (check(s.substr(0, i)) || check(s.substr(i, i)))
            return answer(i);

        if (check(s.substr(0, n / i)) || check(s.substr(n / i, n / i)))
            k = n / i;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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
