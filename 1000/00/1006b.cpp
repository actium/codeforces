#include <algorithm>
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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i + 1;
    
    std::sort(p.begin(), p.end(), [&a](size_t x, size_t y) { return a[x-1] > a[y-1]; });
    p.resize(k);
    std::sort(p.begin(), p.end());

    std::vector<unsigned> t(k);
    unsigned s = 0;
    for (size_t i = 0, x = 0; i < k; ++i) {
        t[i] = p[i] - x;
        x = p[i];
        s += a[x-1];
    }
    t.back() += n - p.back();

    answer(s, t);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

