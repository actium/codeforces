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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& b)
{
    const size_t n = b.size();

    std::sort(b.begin(), b.end());

    std::vector<unsigned> c(n, 1);
    for (size_t i = 1; i < n; ++i) {
        if (b[0].first + b[i].second >= b[i].first)
            continue;

        const auto begin = b.begin() + 1, end = begin + i;

        const auto x = std::lower_bound(begin, end, std::make_pair(b[i].first - b[i].second, 0u));
        if (x != end)
            c[i] += c[x - begin];
    }

    answer(n - *std::max_element(c.begin(), c.end()));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
