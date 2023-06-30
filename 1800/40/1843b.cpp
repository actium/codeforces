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

void answer(integer x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    integer s = 0;
    unsigned k = 0, p = 1;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;

        s += abs(a[i]);
        k += p * (a[i] < 0);
        p = (a[i] > 0);
    }

    answer(s, k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
