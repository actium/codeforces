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

void solve(const std::vector<unsigned>& c, const std::vector<unsigned>& k)
{
    const size_t n = c.size(), m = k.size();

    for (size_t i = 0; i < n; ++i) {
        std::vector<unsigned> f(m);
        for (size_t j = i; j < n; ++j) {
            ++f[c[j]-1];

            if (f == k)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(n), k(m);
    std::cin >> c >> k;

    solve(c, k);

    return 0;
}
