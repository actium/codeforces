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

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::vector<unsigned> p(n);
    for (size_t i = 1; i < n; ++i) {
        if (h[i] >= h[i-1])
            p[i] = p[i-1] + 1;
    }

    std::vector<unsigned> s(n);
    for (size_t i = 1; i < n; ++i) {
        if (h[n-1-i] >= h[n-i])
            s[n-1-i] = s[n-i] + 1;
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k = std::max(k, p[i] + 1 + s[i]);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}

