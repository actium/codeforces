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

    unsigned b = 1;
    while (b * b <= n)
        ++b;

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + a[i], x = 1; j < n && x < b; j += a[i], ++x)
            k += (a[j] == x);

        if (a[i] < b)
            continue;

        for (size_t j = i - a[i], x = 1; j < n && x < b; j -= a[i], ++x)
            k += (a[j] == x);
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
