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

void solve(const std::vector<std::vector<unsigned>>& a, unsigned k)
{
    const size_t n = a.size();

    unsigned q[2] = {};
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (a[i][j] != a[n-1-i][n-1-j])
                ++q[a[i][j]];
        }
    }

    const unsigned c = std::min(q[0], q[1]);
    answer(c <= k && ((k - c) % 2 == 0 || n % 2 == 1));
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a, k);
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
