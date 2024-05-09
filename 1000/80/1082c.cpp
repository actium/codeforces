#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void solve(size_t m, std::vector<std::pair<unsigned, int>>& p)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
    });

    std::vector<integer> v(1 + n);
    {
        std::vector<std::pair<unsigned, integer>> s(1 + m);
        for (const std::pair<unsigned, int>& e : p) {
            s[e.first].second += e.second;
            ++s[e.first].first;

            if (s[e.first].second > 0)
                v[s[e.first].first] += s[e.first].second;
        }
    }

    answer(*std::max_element(v.begin(), v.end()));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, int>> p(n);
    std::cin >> p;

    solve(m, p);

    return 0;
}
