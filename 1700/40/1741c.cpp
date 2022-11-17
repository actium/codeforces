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
    const size_t n = a.size();

    const auto check = [&](size_t x, unsigned s) {
        unsigned t = 0, w = x;
        for (size_t p = x; x < n; ++x) {
            t += a[x];
            if (t == s) {
                w = std::max<unsigned>(w, x - p + 1);
                p = x + 1;
                t = 0;
            }
        }
        return t == 0 ? w : ~0u;
    };

    unsigned s = 0, x = n;
    for (size_t i = 0; i < n; ++i) {
        s += a[i];
        x = std::min(x, check(i + 1, s));
    }

    answer(x);
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
