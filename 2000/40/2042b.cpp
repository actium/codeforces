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

void solve(const std::vector<unsigned>& c)
{
    unsigned f[1000] = {};
    for (const unsigned x : c)
        ++f[x-1];

    unsigned k = 0, q = 0;
    for (size_t i = 0; i < 1000; ++i) {
        k += (f[i] == 1);
        q += (f[i] >= 2);
    }

    answer((k + 1) / 2 * 2 + q);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
