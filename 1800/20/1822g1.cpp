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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    integer t = 0;
    for (auto i = f.begin(); i != f.end(); ++i) {
        t += integer(i->second) * (i->second - 1) * (i->second - 2);

        for (unsigned b = 2; i->first * b * b <= f.rbegin()->first; ++b) {
            const auto j = f.find(i->first * b);
            if (j == f.end())
                continue;

            const auto k = f.find(j->first * b);
            if (k != f.end())
                t += integer(i->second) * j->second * k->second;
        }
    }

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
