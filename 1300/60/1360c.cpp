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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    size_t f[2] = {};
    size_t g = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t p = a[i] % 2;
        ++f[p];

        if (i > 0 && a[i] - a[i-1] == 1)
            ++g;
    }

    if (f[0] % 2 == 0 && f[1] % 2 == 0)
        return answer(true);

    if (f[0] % 2 == 1 && f[1] % 2 == 1 && g > 0)
        return answer(true);

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

