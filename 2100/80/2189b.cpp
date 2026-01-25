#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Jump {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Jump& jump)
{
    return input >> jump.a >> jump.b >> jump.c;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<Jump>& d, integer x)
{
    integer p = 0;
    for (const auto& e : d) {
        const integer r = (e.b - 1LL) * e.a;
        x -= r;
        p = std::max(p, r + e.a - e.c);
    }

    if (x <= 0)
        return answer(0);

    if (x > 0 && p != 0)
        return answer((x + p - 1) / p);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer x;
    std::cin >> x;

    std::vector<Jump> d(n);
    std::cin >> d;

    solve(d, x);
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
