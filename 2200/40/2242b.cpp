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

template <typename Predicate>
bool cut(const std::vector<unsigned>& a, size_t& x, Predicate&& predicate)
{
    const size_t n = a.size();

    unsigned f[4] = {};
    do {
        ++f[a[x]];
        ++x;
    } while (x < n && predicate(f));

    return x < n;
}

void solve(const std::vector<unsigned>& a)
{
    size_t x = 0;

    if (!cut(a, x, [&](const unsigned f[4]) { return f[1] < f[2] + f[3] || f[1] > f[2] + f[3] && a[x] == 3; }))
        return answer(false);

    if (!cut(a, x, [](const unsigned f[4]) { return f[1] + f[2] < f[3]; }))
        return answer(false);

    answer(true);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
