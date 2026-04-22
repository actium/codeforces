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

void solve(const std::vector<unsigned>& a, unsigned m)
{
    const size_t n = a.size();

    for (size_t i = 1, c = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            c = 0;

        if (++c == m)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
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
