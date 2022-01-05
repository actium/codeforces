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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, size_t x)
{
    const size_t n = a.size();

    std::vector<unsigned> b = a;
    std::sort(b.begin(), b.end());

    for (size_t i = 0; i < n; ++i) {
        if (b[i] != a[i] && i < x && n-1-i < x)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, x;
    std::cin >> n >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
