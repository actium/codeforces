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

void solve(std::vector<unsigned>& v, unsigned a)
{
    unsigned p = 0, q = 0;
    for (const unsigned x : v) {
        p += (x < a);
        q += (a < x);
    }

    answer(p < q ? a + 1 : a - 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a;
    std::cin >> a;

    std::vector<unsigned> v(n);
    std::cin >> v;

    solve(v, a);
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
