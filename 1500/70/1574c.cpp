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

void solve(std::vector<integer>& a, const std::vector<std::pair<integer, integer>>& q)
{
    std::sort(a.begin(), a.end());

    integer s = 0;
    for (const integer x : a)
        s += x;

    for (const auto& r : q) {
        integer d = 0;

        const auto it = std::lower_bound(a.cbegin(), a.cend(), r.first);
        if (it == a.cend()) {
            d = r.first - a.back();
            if (s - a.back() < r.second)
                d += r.second - (s - a.back());
        } else {
            if (s - *it < r.second)
                d = r.second - (s - *it);

            if (it != a.cbegin()) {
                const auto p = std::prev(it);

                integer e = r.first - *p;
                if (s - *p < r.second)
                    e += r.second - (s - *p);

                d = std::min(d, e);
            }
        }

        answer(d);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<integer, integer>> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
