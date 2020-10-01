#include <algorithm>
#include <iostream>
#include <vector>

using distance_t = std::pair<unsigned, unsigned>;

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

void solve(const std::vector<distance_t>& r, const std::vector<distance_t>& s)
{
    std::vector<distance_t> d;
    for (const distance_t& u : r) {
        for (const distance_t& v : s) {
            if (u.first <= v.first && u.second <= v.second)
                d.emplace_back(v.first - u.first + 1, v.second - u.second + 1);
        }
    }

    if (d.empty())
        return answer(0);

    std::sort(d.begin(), d.end(), std::greater<distance_t>());

    distance_t dp = { d.begin()->first, 0 };
    for (const distance_t& x : d) {
        dp.first = std::min(dp.first, x.first + dp.second);
        dp.second = std::max(dp.second, x.second);
    }

    answer(std::min(dp.first, dp.second));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<distance_t> r(n);
    std::cin >> r;

    std::vector<distance_t> s(m);
    std::cin >> s;

    solve(r, s);

    return 0;
}

