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

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    unsigned f[2] = {}, x = 0, t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (++f[a[j]]; f[0] > k; --f[a[i++]]);

        if (f[0] + f[1] > t) {
            t = f[0] + f[1];
            x = i;
        }
    }

    for (size_t i = x; i < n && k != 0; ++i) {
        k -= (a[i] == 0);
        a[i] = 1;
    }

    answer(t, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
