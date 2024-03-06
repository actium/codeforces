#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned search(const std::array<unsigned, 7>& a, unsigned r)
{
    unsigned c = 0, k = ~0u;
    for (size_t i = 0, j = 0; j < 14; ++j) {
        c += a[j % 7];
        while (c > r)
            c -= a[i++ % 7];

        while (c == r && a[i % 7] == 0)
            ++i;

        if (c == r)
            k = std::min<unsigned>(k, j - i + 1);
    }
    return k;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<unsigned, 7>& a, unsigned k)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    unsigned q = k / s, r = k % s;
    if (r == 0) {
        --q;
        r += s;
    }

    answer(q * 7 + search(a, r));
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    std::array<unsigned, 7> a;
    std::cin >> a;

    solve(a, k);
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
