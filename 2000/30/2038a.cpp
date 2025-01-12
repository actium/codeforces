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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned k)
{
    using integer = unsigned long long;

    const size_t n = a.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = a[i] / b[i];

    integer p = 0;
    for (const unsigned x : c)
        p += x;

    if (p < k)
        c.assign(n, 0);

    for (size_t i = 0; i < n && p > k; ++i) {
        const unsigned d = std::min<integer>(p - k, c[i]);
        c[i] -= d;
        p -= d;
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}
