#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using player_t = std::pair<std::string, unsigned>;

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

void answer(const std::vector<std::pair<std::string, std::string>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<std::string, std::string>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<player_t>& s)
{
    std::sort(s.begin(), s.end());

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i].first == s[i-1].first)
            s.erase(--i + s.begin());
    }

    std::sort(s.begin(), s.end(), [](const player_t& a, const player_t& b) { return a.second < b.second; });

    const size_t m = s.size();

    std::vector<std::pair<std::string, std::string>> v(m);
    for (size_t i = 0; i < m; ++i) {
        v[i].first = s[i].first;

        const auto it = std::upper_bound(s.begin(), s.end(), s[i].second, [](unsigned x, const player_t& p) {
            return x < p.second;
        });

        const unsigned k = std::distance(it, s.end());
        if (100 * k > 50 * m)
            v[i].second = "noob";
        else if (100 * k > 20 * m)
            v[i].second = "random";
        else if (100 * k > 10 * m)
            v[i].second = "average";
        else if (100 * k > 1 * m)
            v[i].second = "hardcore";
        else
            v[i].second = "pro";
    }

    answer(v);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
