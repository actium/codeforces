#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (a[i] == a[j])
                return answer(false);
        }
    }

    for (unsigned i = 2; i <= n / 2; ++i) {
        std::vector<unsigned> f(i);
        for (const integer x : a)
            ++f[x % i];

        unsigned b = ~0u;
        for (const unsigned v : f)
            b = std::min(b, v);

        if (b > 1)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);
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
