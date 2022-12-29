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

void solve(const std::vector<unsigned>& a)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    unsigned k = ~0u;
    for (unsigned x : a) {
        unsigned q = 0;
        for (unsigned t = s; t % 2 != 0; ++q) {
            t -= x;
            x /= 2;
            t += x;
        }

        k = std::min(k, q);
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
