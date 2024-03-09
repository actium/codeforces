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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t k = a[0].size(), m = 1 << k;

    std::vector<unsigned> f(m);
    for (const std::vector<unsigned>& v : a) {
        unsigned x = 0;
        for (const unsigned q : v)
            x = x << 1 | q;

        ++f[x];
    }

    for (unsigned i = 1; i < m; ++i) {
        for (unsigned j = 1; j < m; ++j) {
            if ((i & j) == 0 && f[i] * f[j] != 0)
                return answer(true);
        }
    }

    answer(f[0] != 0);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(k));
    std::cin >> a;

    solve(a);

    return 0;
}
