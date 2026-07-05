#include <iostream>
#include <vector>

using integer = long long;

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

void solve(std::vector<integer>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        if (a[i] > b[i])
            return answer(false);

        if (i + 1 < n)
            a[i+1] -= b[i] - a[i];
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);
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
