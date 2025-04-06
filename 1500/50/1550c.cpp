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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = n + n - 1;
    for (size_t i = 2; i < n; ++i) {
        if (a[i] >= a[i-1] && a[i-1] >= a[i-2])
            continue;

        if (a[i] <= a[i-1] && a[i-1] <= a[i-2])
            continue;

        ++k;

        if (i+1 == n)
            continue;

        if (a[i+1] >= a[i] && a[i] >= std::min(a[i-1], a[i-2]))
            continue;

        if (a[i+1] >= a[i-1] && a[i-1] >= a[i-2])
            continue;

        if (a[i+1] <= a[i] && a[i] <= std::max(a[i-1], a[i-2]))
            continue;

        if (a[i+1] <= a[i-1] && a[i-1] <= a[i-2])
            continue;

        ++k;
    }

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
