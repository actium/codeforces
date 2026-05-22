#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& w)
{
    unsigned f[3] = {};
    for (const unsigned x : w)
        ++f[x];

    unsigned k = std::min(f[1], f[2]);
    f[1] -= k;
    f[2] -= k;

    k += f[0];
    k += f[1] / 3;
    k += f[2] / 3;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
