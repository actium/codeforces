#include <iostream>
#include <vector>

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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    unsigned f[2] = {};
    for (const unsigned x : a)
        ++f[x];

    for (const auto [t, x] : q) {
        if (t == 1) {
            unsigned& y = a[x-1];
            --f[y];
            y = 1 - y;
            ++f[y];
        } else {
            answer(f[1] < x ? 0 : 1);
        }
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}

