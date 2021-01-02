#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    unsigned a = 0, sa = 0, b = 0, sb = 0, k = 0;
    for (size_t i = 0, j = n; i < j; ++k) {
        if (a <= b) {
            while (i < j && a <= b)
                a += c[i++];

            sa += a;
            b = 0;
        } else {
            while (i < j && b <= a)
                b += c[--j];

            sb += b;
            a = 0;
        }
    }

    answer(k, sa, sb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

