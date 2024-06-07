#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& k)
{
    const size_t n = k.size();

    unsigned p = 1;
    for (size_t i = 0; i < n; ++i)
        p = std::lcm(p, k[i]);

    std::vector<unsigned> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = p / k[i];

    unsigned v = 0;
    for (size_t i = 0; i < n; ++i)
        v += x[i];

    v < p ? answer(x) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> k(n);
    std::cin >> k;

    solve(k);
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
