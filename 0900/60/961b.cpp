#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& t, size_t k)
{
    const size_t n = a.size();

    unsigned s = 0;
    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i) {
        s += t[i] * a[i];
        p[i+1] = p[i] + (t[i] ^ 1) * a[i];
    }

    unsigned x = 0;
    for (size_t i = k; i <= n; ++i)
        x = std::max(x, p[i] - p[i-k]);

    answer(s + x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(a, t, k);

    return 0;
}

