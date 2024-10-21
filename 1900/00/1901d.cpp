#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(n);
    p[0] = a[0];
    for (size_t i = 1; i < n; ++i)
        p[i] = std::max(p[i-1] + 1, a[i]);

    std::vector<unsigned> s(n);
    s[n-1] = a[n-1];
    for (size_t i = n-2; ~i != 0; --i)
        s[i] = std::max(s[i+1] + 1, a[i]);

    unsigned x = ~0u;
    for (size_t i = 0; i < n; ++i) {
        unsigned sp = s[i];
        if (i > 0 && s[i] < p[i-1] + (n-i))
            sp += p[i-1] + (n-i) - s[i];

        unsigned pp = p[i];
        if (i < n-1 && p[i] < s[i+1] + (i+1))
            pp += s[i+1] + (i+1) - p[i];

        x = std::min(x, std::max(sp, pp));
    }

    answer(x);
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
