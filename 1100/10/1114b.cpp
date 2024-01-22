#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x, const std::vector<size_t>& v)
{
    std::cout << x << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a, size_t m, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return a[i] > a[j];
    });

    p.resize(m * k);

    integer t = 0;
    for (const size_t i : p)
        t += a[i];

    std::sort(p.begin(), p.end());

    std::vector<size_t> s;
    for (size_t i = 1; i < k; ++i)
        s.push_back(p[i*m-1]);

    answer(t, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}
