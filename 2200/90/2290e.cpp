#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<int> d(n+k+1);
    for (size_t i = 0; i < n; ++i) {
        a[n-1-i] += d[i];
        a[n-1-i] %= 2;

        d[i+1] += d[i] + a[n-1-i];
        d[i+k+1] -= a[n-1-i];
    }

    unsigned p = 0;
    for (const unsigned x : a)
        p += x;

    answer(p % 2 == 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
