#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    unsigned x = 0;
    for (const unsigned q : a)
        x ^= q;

    if (n % 2 == 0) {
        unsigned y = 0;
        for (const unsigned q : b)
            y |= x & q;

        answer(x ^ y, x);
    } else {
        unsigned y = 0;
        for (const unsigned q : b)
            y |= ~x & q;

        answer(x, x ^ y);
    }
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
