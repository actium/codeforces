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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<int> f(1+n);
    {
        std::pair<unsigned, unsigned> maximums = { 0, 0 };
        for (const unsigned x : p) {
            if (x < maximums.second)
                continue;

            if (x < maximums.first) {
                ++f[maximums.first];
                maximums.second = x;
            } else {
                --f[x];
                maximums.second = maximums.first;
                maximums.first = x;
            }
        }
    }

    unsigned x = 1;
    for (unsigned i = 2; i <= n; ++i) {
        if (f[i] > f[x])
            x = i;
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
