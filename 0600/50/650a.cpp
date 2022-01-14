#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using point_t = std::pair<int, int>;
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

void solve(std::vector<point_t>& p)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end());

    integer k = 0;

    std::map<int, unsigned> fx, fy;
    for (size_t i = 0, j = 0; i < n; ++i) {
        unsigned& x = fx[p[i].first];
        k += x++;

        unsigned& y = fy[p[i].second];
        k += y++;

        if (i > 0 && p[i] == p[i-1])
            k -= i - j;

        if (i > 0 && p[i] != p[i-1])
            j = i;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
