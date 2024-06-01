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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& w, unsigned t, unsigned r)
{
    const unsigned n = t + w.back() + 1;

    std::vector<unsigned> s(n), c(n);
    for (auto it = w.rbegin(); it != w.rend(); ++it) {
        for (size_t i = *it; i < *it + t && c[*it + t] < r; ++i) {
            if (s[i] == 1)
                continue;

            s[i] = 1;
            for (unsigned j = 1; j <= t && i + j < n; ++j)
                ++c[i + j];
        }

        if (c[*it + t] < r)
            return no_answer();
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++ i)
        k += s[i];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t m;
    std::cin >> m;

    unsigned t, r;
    std::cin >> t >> r;

    std::vector<unsigned> w(m);
    std::cin >> w;

    solve(w, t, r);

    return 0;
}
