#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

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

void solve(const std::vector<unsigned>& a)
{
    using integer = unsigned long long;

    const size_t n = a.size();

    integer s = 0;
    for (const unsigned x : a) {
        integer v = 0;
        for (unsigned b = 1000000000; b != 0; b /= 10) {
            v *= 100;
            v += x / b % 10;
        }

        v %= M;
        s += (v + v * 10) % M * n;
        s %= M;
    }

    answer(s);
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
