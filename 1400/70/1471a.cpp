#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const auto cd = [x](integer a) {
        return (a + x - 1) / x;
    };

    integer s[2] = {};
    for (const unsigned q : a) {
        s[0] += q;
        s[1] += cd(q);
    }

    answer(cd(s[0]), s[1]);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

