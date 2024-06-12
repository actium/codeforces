#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

    const auto count = [&](size_t s) {
        const size_t x = s + n - 1;

        std::vector<unsigned> t(2 * n, oo);
        t[s] = 0;
        for (size_t i = s + 1; i <= x; ++i)
            t[i] = (s + a[i%n] >= i ? 1 : *std::min_element(t.begin() + i - a[i%n], t.begin() + i) + 1);

        return t[x];
    };

    unsigned t = 0;
    for (size_t i = 0; i < n; ++i)
        t += count(i);

    answer(t);
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
