#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& ab, unsigned n)
{
    const size_t m = ab.size();

    std::sort(ab.begin(), ab.end(), [](const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y) { return x.second > y.second; });

    unsigned long long x = 0;
    for (size_t i = 0; i < m && n > 0; ++i) {
        const unsigned k = std::min(ab[i].first, n);
        x += k * ab[i].second;
        n -= k;
    }

    answer(x);
}

int main()
{
    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> ab(m);
    std::cin >> ab;

    solve(ab, n);

    return 0;
}

