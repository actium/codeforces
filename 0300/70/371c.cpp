#include <array>
#include <iostream>
#include <string>

using integer = unsigned long long;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::array<unsigned, 3>& n, const std::array<unsigned, 3>& p, integer r)
{
    unsigned f[256] = {};
    for (const char c : s)
        ++f[c];

    const auto check = [&](integer k) {
        const integer c1 = (std::max<integer>(k * f['B'], n[0]) - n[0]) * p[0];
        const integer c2 = (std::max<integer>(k * f['S'], n[1]) - n[1]) * p[1];
        const integer c3 = (std::max<integer>(k * f['C'], n[2]) - n[2]) * p[2];
        return c1 + c2 + c3 <= r;
    };

    integer lb = 0, ub = r + 101;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    std::array<unsigned, 3> n, p;
    std::cin >> n >> p;

    integer r;
    std::cin >> r;

    solve(s, n, p, r);

    return 0;
}
