#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& l)
{
    std::unordered_map<unsigned, unsigned> m;
    for (const unsigned x : l)
        ++m[x];

    unsigned z = 0;
    for (const auto& [l, c] : m)
        z = std::max(z, c);

    answer(z, m.size());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n);
    std::cin >> l;

    solve(l);

    return 0;
}

