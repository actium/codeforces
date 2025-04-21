#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(n);
    p[0] = a[0];
    for (size_t i = 1; i < n; ++i)
        p[i] = std::max(p[i-1], a[i]);

    std::vector<unsigned> s(n);
    s[n-1] = a[n-1];
    for (size_t i = n-2; ~i != 0; --i)
        s[i] = std::min(s[i+1], a[i]);

    for (size_t i = n-2; ~i != 0; --i) {
        if (p[i] > s[i+1])
            p[i] = p[i+1];
    }

    answer(p);
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
