#include <algorithm>
#include <iostream>
#include <string>
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

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, std::vector<std::pair<unsigned, std::string>>& v)
{
    integer k = 0, s = 0;

    const auto g = [&](unsigned& q, unsigned p) {
        if (q == 0 && c == 0)
            return;

        --(q > 0 ? q : c);
        ++k;
        s += p;
    };

    std::sort(v.begin(), v.end());

    for (const auto& e : v)
        g(e.second == "USB" ? a : b, e.first);

    answer(k, s);
}

int main()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, std::string>> v(m);
    std::cin >> v;

    solve(a, b, c, v);

    return 0;
}
