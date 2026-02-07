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

void answer(integer x)
{
    std::cout << x << '\n';
}

integer count(const std::vector<unsigned>& s, const std::vector<unsigned>& t)
{
    const size_t n = s.size();

    const auto check = [&](size_t x) {
        for (size_t i = 0; i < n; ++i) {
            const size_t j = (x + i) % n;
            if (t[j] <= s[i])
                return 0;
        }
        return 1;
    };

    integer k = 0;
    for (size_t i = 0; i < n; ++i)
        k += check(i);

    return k;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    answer(count(a, b) * count(b, c) * a.size());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n), c(n);
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
