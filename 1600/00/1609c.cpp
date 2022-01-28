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

bool is_composite[1 + 1000000] = {};

void initialize() noexcept
{
    is_composite[0] = true;
    is_composite[1] = true;

    for (integer i = 2; i <= 1000000; ++i) {
        if (is_composite[i])
            continue;

        for (integer j = i * i; j <= 1000000; j += i)
            is_composite[j] = true;
    }
}

void solve(std::vector<unsigned>& a, unsigned e)
{
    const size_t n = a.size();

    std::vector<unsigned> p(e+n);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 1)
            p[e+i] = p[i] + 1;
    }

    std::vector<unsigned> s(n+e);
    for (size_t i = n; i-- > 0; ) {
        if (a[i] == 1)
            s[i] = s[i+e] + 1;
    }

    integer q = 0;
    for (size_t i = 0; i < n; ++i) {
        if (is_composite[a[i]])
            continue;

        const integer x = p[i], y = s[i+e];
        q += x * (y + 1) + y;
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned e;
    std::cin >> e;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, e);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
