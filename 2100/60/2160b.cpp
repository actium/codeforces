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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<integer>& b)
{
    const size_t n = b.size();

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = 1 + i;

    for (size_t i = 1; i < n; ++i) {
        const unsigned d = b[i] - b[i-1];
        if (d <= i)
            a[i] = a[i-d];
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> b(n);
    std::cin >> b;

    solve(b);
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