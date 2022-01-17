#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& d, unsigned r, unsigned m)
{
    const size_t n = d.size();

    const auto f = [](const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y) {
        return std::make_pair(x.second, x.first) > std::make_pair(y.second, y.first);
    };

    std::sort(d.begin(), d.end(), f);

    integer s = 0;
    for (const auto& x : d)
        s += x.first;

    integer k = 0;
    for (const integer t = 1ull * m * n; s < t; d.pop_back()) {
        const integer b = std::min<integer>(r - d.back().first, t - s);
        k += b * d.back().second;
        s += b;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned r, m;
    std::cin >> r >> m;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d, r, m);

    return 0;
}
