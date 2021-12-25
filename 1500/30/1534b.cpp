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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer s = a.back();
    for (size_t i = 0; i < n; ++i) {
        const unsigned last = (i > 0 ? a[i-1] : 0);
        const unsigned next = (i+1 < n ? a[i+1] : 0);

        if (last < a[i] && a[i] > next)
            s -= a[i] - std::max(last, next);

        s += (a[i] > last ? a[i] - last : last - a[i]);
    }

    answer(s);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
