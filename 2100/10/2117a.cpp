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

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 1)
            p.push_back(i);
    }

    answer(p.empty() || p.back() - p.front() < x);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
