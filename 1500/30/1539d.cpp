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

void solve(std::vector<std::pair<integer, integer>>& p)
{
    std::sort(p.begin(), p.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });

    integer k = 0, s = 0;
    for (size_t i = 0; i < p.size(); ) {
        if (k < p[i].second) {
            const integer d = p[i].second - k;
            if (d >= p.back().first) {
                s += 2 * p.back().first;
                k += p.back().first;
                p.pop_back();
            } else {
                s += 2 * d;
                k += d;
                p.back().first -= d;
            }
        } else {
            s += p[i].first;
            k += p[i].first;
            ++i;
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<integer, integer>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
