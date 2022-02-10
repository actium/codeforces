#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, int>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, int>& x : v)
        std::cout << (x.second < 0 ? '-' : '+') << ' ' << 1+x.first << ' ' << std::abs(x.second) << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, int>> d(n + 1);
    for (unsigned b = 1; b <= 1000; ++b) {
        std::vector<std::pair<size_t, int>> c;
        for (size_t j = 0; j < n; ++j) {
            if (a[j] != b + j * k)
                c.emplace_back(j, b + j * k - a[j]);
        }

        if (c.size() < d.size())
            d.swap(c);
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
