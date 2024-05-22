#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<std::pair<unsigned, unsigned>> f;
    for (unsigned q = n, x = 1; q != 0; q /= 2, x *= 2)
        f.emplace_back(q / 2 + q % 2, x);

    if (n >> __builtin_clz(1) - __builtin_clz(n) - 1 == 3)
        f.back().second = f.back().second / 2 * 3;

    std::vector<unsigned> v;
    v.reserve(n);
    for (const std::pair<unsigned, unsigned>& e : f)
        v.insert(v.end(), e.first, e.second);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
