#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s[0].length();

    std::vector<unsigned> t(n);
    for (const std::string& r : s) {
        for (size_t i = 0; i < n; ++i)
            t[i] |= 1 << (r[i] - 'a');
    }

    std::string p = s[0];

    const auto check = [&](size_t k) {
        std::vector<unsigned> q(k, ~0u);
        for (size_t i = 0; i * k < n; ++i) {
            for (size_t j = 0; j < k; ++j)
                q[j] &= t[i * k + j];
        }

        std::string r(k, 'a');
        for (size_t j = 0; j < k; ++j) {
            if (q[j] == 0)
                return;

            r[j] += __builtin_ctz(q[j]);
        }
        p = r;
    };

    for (size_t i = 1; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        if (i < p.length())
            check(i);

        if (n / i < p.length())
            check(n / i);
    }

    const size_t k = p.length();
    while (p.length() < n)
        p.push_back(p[p.length() % k]);

    answer(p);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(k);
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
