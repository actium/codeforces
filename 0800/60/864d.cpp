#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1 + n);
    for (const unsigned x : a)
        ++f[x];

    unsigned k = 0;

    std::vector<bool> v(1 + n);
    for (size_t i = 0, j = 1; i < n; ++i) {
        while (j <= n && (v[j] || f[j] != 0 && a[i] != j))
            ++j;

        --f[a[i]];

        if (v[a[i]] || f[a[i]] != 0 && a[i] > j) {
            a[i] = j;
            ++k;
        }

        v[a[i]] = true;
    }

    answer(k, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
