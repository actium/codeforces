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

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    unsigned r = 0;
    for (const int x : a) {
        unsigned d = ~0u;

        const auto it = std::lower_bound(b.begin(), b.end(), x);
        if (it != b.end())
            d = std::min<unsigned>(d, *it - x);

        if (it != b.begin())
            d = std::min<unsigned>(d, x - *std::prev(it));

        r = std::max(r, d);
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
