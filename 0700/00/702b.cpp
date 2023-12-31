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
    integer k = 0;

    std::map<unsigned, unsigned> f;
    for (const unsigned x : a) {
        for (unsigned p = 1u << 30; p > x; p >>= 1) {
            const auto it = f.find(p - x);
            if (it != f.end())
                k += it->second;
        }

        ++f[x];
    }

    answer(k);
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
