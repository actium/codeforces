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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), k = n / 2;

    if (n % 2 == 1 && a[k] != b[k])
        return answer(false);

    for (size_t i = k - 1, j = k + n % 2; j < n; --i, ++j) {
        size_t d = 0;
        while (d <= i && std::minmax(a[i-d], a[j+d]) != std::minmax(b[i], b[j]))
            ++d;

        if (d > i)
            return answer(false);

        std::reverse(a.begin(), a.begin() + i - d + 1);
        std::reverse(a.begin() + j + d, a.end());

        if (a[0] != b[i])
            std::swap(a.front(), a.back());

        std::reverse(a.begin(), a.begin() + i + 1);
        std::reverse(a.begin() + j, a.end());
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

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
