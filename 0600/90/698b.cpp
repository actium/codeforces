#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';

    const char* separator = "";
    for (const unsigned v : y) {
        std::cout << separator << v;
        separator = " ";
    }
    std::cout << '\n';
}

unsigned fix(std::vector<unsigned>& a, size_t u, std::vector<unsigned>& v, size_t x)
{
    if (v[u] == 1 && a[u] != x + 1) {
        a[u] = x + 1;
        return 1;
    }

    unsigned k = 0;
    if (v[u] == 0) {
        v[u] = 1;
        k = fix(a, a[u]-1, v, x);
        v[u] = 2;
    }
    return k;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    while (x < n && a[x] != x + 1)
        ++x;

    if (x == n) {
        std::vector<bool> v(n);
        for (x = 0; !v[x]; x = a[x] - 1)
            v[x] = true;
    }

    unsigned k = 0;
    {
        std::vector<unsigned> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (v[i] == 0)
                k += fix(a, i, v, x);
        }
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
