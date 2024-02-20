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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1 + n);
    for (const unsigned x : a) {
        if (x > n)
            return no_answer();

        ++f[x];
    }

    for (size_t i = 2; i <= n; ++i) {
        if (f[i] > f[i-1])
            return no_answer();
    }

    const unsigned k = f[1];

    std::vector<unsigned> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = f[a[i]]--;

    answer(k, x);
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
