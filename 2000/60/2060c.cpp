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

void solve(const std::vector<unsigned>& x, unsigned k)
{
    std::vector<unsigned> f(k);
    for (const unsigned v : x) {
        if (v < k)
            ++f[v];
    }

    unsigned q = 0;
    for (size_t i = 1; i < k; ++i) {
        q += (2 * i == k ? f[i] / 2 : std::min(f[i], f[k-i]));
        f[i] = 0;
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, k);
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
