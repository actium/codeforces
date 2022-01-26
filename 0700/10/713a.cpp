#include <iostream>
#include <map>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<char, integer>>& r)
{
    std::map<integer, unsigned> f;
    for (const auto& q : r) {
        integer x = q.second, y = 0;
        for (int i = 18; i >= 0; --i) {
            y |= (x % 2) << i;
            x /= 10;
        }

        if (q.first == '+')
            ++f[y];

        if (q.first == '-')
            --f[y];

        if (q.first == '?')
            answer(f[y]);
    }
}

int main()
{
    size_t t;
    std::cin >> t;

    std::vector<std::pair<char, integer>> r(t);
    std::cin >> r;

    solve(r);

    return 0;
}
