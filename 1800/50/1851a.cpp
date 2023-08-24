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

void solve(unsigned m, unsigned k, unsigned t, const std::vector<unsigned>& h)
{
    unsigned c = 0;
    for (const unsigned x : h) {
        const unsigned d = (x < t ? t - x : x - t);
        if (d != 0 && d % k == 0 && d / k < m)
            ++c;
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k, t;
    std::cin >> m >> k >> t;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(m, k, t, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
