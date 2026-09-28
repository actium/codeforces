#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const auto evaluate = [&](unsigned q) {
        integer v = 0;
        for (const unsigned x : a) {
            if (x % q == 0)
                v += x;
        }
        return v;
    };

    integer v = 0;
    for (unsigned d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            v = std::max(v, evaluate(d));
            while (x % d == 0)
                x /= d;
        }
    }

    if (x != 1)
        v = std::max(v, evaluate(x));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
