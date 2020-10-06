#include <algorithm>
#include <iostream>
#include <vector>

using segment_t = std::pair<unsigned, unsigned>;

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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<segment_t>& c, const std::vector<segment_t>& p)
{
    unsigned d = 0;
    {
        const auto a = std::min_element(c.cbegin(), c.cend(), [](const segment_t& a, const segment_t& b) { return a.second < b.second; });
        const auto b = std::max_element(p.cbegin(), p.cend(), [](const segment_t& a, const segment_t& b) { return a.first < b.first; });
        if (a->second < b->first)
            d = std::max(d, b->first - a->second);
    }
    {
        const auto a = std::max_element(c.cbegin(), c.cend(), [](const segment_t& a, const segment_t& b) { return a.first < b.first; });
        const auto b = std::min_element(p.cbegin(), p.cend(), [](const segment_t& a, const segment_t& b) { return a.second < b.second; });
        if (b->second < a->first)
            d = std::max(d, a->first - b->second);
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<segment_t> c(n);
    std::cin >> c;

    size_t m;
    std::cin >> m;

    std::vector<segment_t> p(m);
    std::cin >> p;

    solve(c, p);

    return 0;
}

