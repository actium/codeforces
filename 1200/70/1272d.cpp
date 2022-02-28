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

    std::vector<unsigned> p(n, 1);
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            p[i] += p[i-1];
    }

    std::vector<unsigned> s(n, 1);
    for (size_t i = n-1; i > 0; --i) {
        if (a[i-1] < a[i])
            s[i-1] += s[i];
    }

    unsigned k = std::max(p.back(), s.front());
    for (size_t i = 1; i < n-1; ++i) {
        k = std::max(k, p[i]);
        k = std::max(k, s[i]);

        if (a[i-1] < a[i+1])
            k = std::max(k, p[i-1] + s[i+1]);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
