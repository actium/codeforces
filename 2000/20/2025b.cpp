#include <iostream>
#include <vector>

constexpr unsigned M = 1'000'000'007;

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

void solve(const std::vector<unsigned>& n, const std::vector<unsigned>& k)
{
    std::vector<unsigned> t(100000);
    t[0] = 1;
    for (size_t i = 1; i < 100000; ++i)
        t[i] = t[i-1] * 2 % M;

    for (const unsigned x : k)
        answer(t[x]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    std::vector<unsigned> n(t), k(t);
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
