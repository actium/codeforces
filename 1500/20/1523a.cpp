#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t m)
{
    const size_t n = s.length();

    std::string t = s;

    const auto fill = [&t](size_t x, size_t k) {
        for (size_t i = 0; i < k; ++i)
            t[x + i] = '1';
    };

    for (size_t i = 0; i < n; ) {
        const size_t a = s.find('0', i);
        if (a == std::string::npos)
            break;

        const size_t b = s.find('1', a + 1);
        if (b == std::string::npos) {
            if (a != 0)
                fill(a, std::min(n - a, m));

            break;
        }

        if (a == 0) {
            const size_t k = std::min(b, m);
            fill(b - k, k);
        } else {
            const size_t k = std::min((b - a) / 2, m);
            fill(a, k);
            fill(b - k, k);
        }

        i = b + 1;
    }

    answer(t);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    solve(s, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
