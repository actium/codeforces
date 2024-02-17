#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

integer C(unsigned n, unsigned k)
{
    integer v = 1;
    {
        for (unsigned i = std::max(k, n - k) + 1; i <= n; ++i)
            v *= i;

        for (unsigned i = 2; i <= std::min(k, n - k); ++i)
            v /= i;
    }
    return v;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    if (f.begin()->second >= 3)
        return answer(C(f.begin()->second, 3));

    if (f.begin()->second + std::next(f.begin())->second >= 3)
        return answer(C(std::next(f.begin())->second, 3 - f.begin()->second));

    answer(std::next(std::next(f.begin()))->second);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
