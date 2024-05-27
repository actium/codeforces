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
void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = std::max(p[i], h[i]);

    std::vector<unsigned> s(1 + n, ~0u);
    for (size_t i = n; i > 0; --i)
        s[i-1] = std::min(s[i], h[i-1]);

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (p[i] <= s[i])
            ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}
