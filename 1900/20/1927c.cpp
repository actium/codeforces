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

void solve(const std::vector<unsigned>&a, const std::vector<unsigned>& b, size_t k)
{
    std::vector<unsigned> c(k);
    for (const unsigned x : a) {
        if (x <= k)
            c[x-1] |= 1;
    }
    for (const unsigned x : b) {
        if (x <= k)
            c[x-1] |= 2;
    }

    unsigned f[4] = {};
    for (const unsigned x : c)
        ++f[x];

    answer(f[0] == 0 && f[1] + f[3] >= k / 2 && f[2] + f[3] >= k / 2);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, k);
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
