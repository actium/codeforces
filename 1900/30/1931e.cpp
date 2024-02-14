#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "Anna", "Sasha" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& a, size_t m)
{
    const size_t n = a.size();

    unsigned k = 0;

    std::vector<unsigned> b(n);
    for (size_t i = 0; i < n; ++i) {
        k += a[i].length();

        for (auto it = a[i].rbegin(); it != a[i].rend() && *it == '0'; ++it)
            ++b[i];
    }

    std::sort(b.begin(), b.end(), std::greater<unsigned>());

    for (size_t i = 0; i < n; i += 2)
        k -= b[i];

    answer(k > m);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a, m);
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
