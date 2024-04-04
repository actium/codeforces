#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, std::vector<std::vector<unsigned>>& f)
{
    const size_t m = f.size();

    std::vector<unsigned> c(1 + n);
    for (size_t i = 0; i < m; ++i) {
        if (f[i].empty())
            return no_answer();

        ++c[f[i].back()];
    }

    std::vector<unsigned> v(m);
    for (size_t i = 0; i < m; ++i) {
        while (f[i].size() > 1 && c[f[i].back()] > (m + 1) / 2) {
            --c[f[i].back()];
            f[i].pop_back();
            ++c[f[i].back()];
        }
        v[i] = f[i].back();
    }

    for (size_t i = 1; i <= n; ++i) {
        if (c[i] > (m + 1) / 2)
            return no_answer();
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> f(m);
    for (size_t i = 0; i < m; ++i) {
        size_t k;
        std::cin >> k;

        f[i].resize(k);
        std::cin >> f[i];
    }

    solve(n, f);
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
