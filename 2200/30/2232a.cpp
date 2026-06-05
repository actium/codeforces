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

void solve(std::vector<unsigned>& a)
{
    const auto count = [&](unsigned x) {
        unsigned c[2] = {};
        for (const unsigned v : a) {
            if (v != x)
                ++c[v > x];
        }
        return std::max(c[0], c[1]);
    };

    unsigned k = ~0u;
    for (const unsigned x : a)
        k = std::min(k, count(x));

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
