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

void solve(const std::vector<unsigned>& a, unsigned r)
{
    unsigned k = 0, q = 0;
    for (const unsigned x : a) {
        const unsigned p = x / 2;
        r -= p;
        k += p * 2;
        q += x % 2;
    }

    answer(q <= r ? k + q : k + 2 * r - q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned r;
    std::cin >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, r);
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
