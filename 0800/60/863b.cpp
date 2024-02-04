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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& w)
{
    const size_t n = w.size();

    std::sort(w.begin(), w.end());

    const auto test = [&](size_t u, size_t v) {
        unsigned s = 0;
        for (size_t i = 0; i < n; ++i) {
            if (i == u || i == v)
                continue;

            const size_t x = i++;
            while (i == u || i == v)
                ++i;

            s += w[i] - w[x];
        }
        return s;
    };

    unsigned v = ~0u;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            v = std::min(v, test(i, j));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(2 * n);
    std::cin >> w;

    solve(w);

    return 0;
}
