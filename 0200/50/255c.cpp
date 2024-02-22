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

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::vector<std::vector<size_t>> p(1000001);
    for (size_t i = 0; i < n; ++i)
        p[b[i]].push_back(i);

    const auto check = [&](unsigned u, unsigned v) -> unsigned {
        unsigned k = 0;
        for (size_t i = 0, j = 0, x = 0; i < p[u].size(); ) {
            if (p[u][i] < x) {
                ++i;
            } else {
                ++k;

                x = p[u][i] + 1;
                std::swap(u, v);
                std::swap(i, j);
            }
        }
        return k;
    };

    std::vector<unsigned> s(b.begin(), b.end());
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());

    unsigned x = 0;
    for (const unsigned u : s) {
        for (const unsigned v : s)
            x = std::max(x, check(u, v));
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
