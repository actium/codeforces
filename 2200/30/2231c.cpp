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

void solve(std::vector<unsigned>& a)
{
    unsigned min = a[0], max = a[0];
    for (const unsigned x : a) {
        min = std::min(min, x);
        max = std::max(max, x);
    }

    unsigned k = 0;
    for (unsigned b = min + (min & 1); b < max; b = min + (min & 1)) {
        max = 0;
        for (unsigned& x : a) {
            while (x > b) {
                if ((x & 1) == 1)
                    ++x;
                else
                    x >>= 1;

                ++k;
            }

            min = std::min(min, x);
            max = std::max(max, x);
        }
    }

    unsigned d = 0;
    for (const unsigned x : a)
        d += (x < max);

    if (min == 1) {
        unsigned e = 0;
        for (const unsigned x : a)
            e += (x == max);

        d = std::min(d, e);
    }

    answer(k + d);
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
