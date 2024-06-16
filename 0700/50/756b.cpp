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

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> c(1+n);
    for (size_t i = 0; i < n; ++i) {
        c[i+1] = c[i] + 20;

        const size_t x = t[i] < 90 ? 0 : std::lower_bound(t.begin(), t.end(), t[i] - 89) - t.begin();
        c[i+1] = std::min(c[i+1], c[x] + 50);

        const size_t y = t[i] < 1440 ? 0 : std::lower_bound(t.begin(), t.end(), t[i] - 1439) - t.begin();
        c[i+1] = std::min(c[i+1], c[y] + 120);
    }

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = c[i+1] - c[i];

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}
