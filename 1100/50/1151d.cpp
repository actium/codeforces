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

void solve(std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end(), [&](const auto& lhs, const auto& rhs) {
        return lhs.first + rhs.second > rhs.first + lhs.second;
    });

    integer s = 0;
    for (integer i = 0; i < n; ++i)
        s += i * p[i].first + (n - 1 - i) * p[i].second;

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
