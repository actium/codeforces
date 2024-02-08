#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& b, std::vector<unsigned>& g)
{
    const size_t m = g.size();

    std::sort(b.begin(), b.end());
    std::sort(g.begin(), g.end());

    if (b.back() > g.front())
        return no_answer();

    integer k = 0;
    for (const unsigned x : b)
        k += 1ull * x * m;

    unsigned q = 0;
    while (!g.empty()) {
        if (b.back() > g.back() || q == m || b.back() < g.back() && q + 1 == m) {
            b.pop_back();
            q = 0;
        } else {
            k += g.back() - b.back();
            g.pop_back();
            ++q;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> b(n), g(m);
    std::cin >> b >> g;

    solve(b, g);

    return 0;
}
