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

    const auto count = [&](size_t s, unsigned x) {
        unsigned k = 0;
        for (unsigned i = s; i < n && a[i] <= x; ++i) {
            if (a[i] == x || a[i] + 1 == x) {
                ++k;
                ++x;
            }
        }
        return k;
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned c = std::max(count(i, a[i]), count(i, a[i] + 1));
        k = std::max(k, c);
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
