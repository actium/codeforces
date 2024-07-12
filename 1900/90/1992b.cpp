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

void solve(unsigned n, const std::vector<unsigned>& a)
{
    unsigned k = 0, v = 0;
    for (const unsigned x : a) {
        k += x - 1;
        v = std::max(v, x);
    }

    answer(n + k - 2 * v + 1);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, a);
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
