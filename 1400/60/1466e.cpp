#include <iostream>
#include <vector>

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

using integer = unsigned long long;

void solve(const std::vector<integer>& x)
{
    constexpr unsigned mod = 1000000007;

    const size_t n = x.size();

    integer f[60] = {}, k[60] = {};
    for (const integer q : x) {
        for (size_t i = 0; i < 60; ++i) {
            const integer r = 1ull << i;
            if (q & r)
                ++f[i];

            k[i] = r % mod;
        }
    }

    integer s = 0;
    for (const integer q : x) {
        integer a = 0, b = 0;
        for (size_t i = 0; i < 60; ++i) {
            if (q & 1ull << i) {
                a = (a + n * k[i]) % mod;
                b = (b + f[i] * k[i]) % mod;
            } else {
                a = (a + f[i] * k[i]) % mod;
            }
        }

        s = (s + a * b) % mod;
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> x(n);
    std::cin >> x;

    solve(x);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

