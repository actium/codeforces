#include <array>
#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n, std::array<std::pair<unsigned, unsigned>, 3>& a)
{
    unsigned s = a[0].second + a[1].second + a[2].second;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        const unsigned k = std::min(s - n, it->second - it->first);
        s -= k, it->second -= k;
    }

    answer(a[0].second, a[1].second, a[2].second);
}

int main()
{
    unsigned n;
    std::cin >> n;

    std::array<std::pair<unsigned, unsigned>, 3> a;
    for (auto& p : a)
        std::cin >> p.first >> p.second;

    solve(n, a);

    return 0;
}

