#include <algorithm>
#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "ugly", "respectable" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<point_t>& p)
{
    std::vector<unsigned> x, y;
    for (const point_t& e : p) {
        x.push_back(e.first);
        y.push_back(e.second);
    }

    std::sort(x.begin(), x.end());
    if (std::unique(x.begin(), x.end()) - x.begin() != 3)
        return answer(false);

    std::sort(y.begin(), y.end());
    if (std::unique(y.begin(), y.end()) - y.begin() != 3)
        return answer(false);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (i == 1 && j == 1)
                continue;

            if (std::find(p.begin(), p.end(), std::make_pair(x[i], y[j])) == p.end())
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    std::vector<point_t> p(8);
    std::cin >> p;

    solve(p);

    return 0;
}
