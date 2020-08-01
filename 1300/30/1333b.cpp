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

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i) {
        const auto it = a.cbegin() + (n - i);

        if (b[n-i] < *it && std::find(a.cbegin(), it, -1) == it)
            return answer(false);

        if (b[n-i] > *it && std::find(a.cbegin(), it, 1) == it)
            return answer(false);
    }

    answer(a[0] == b[0]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<int> b(n);
    std::cin >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

