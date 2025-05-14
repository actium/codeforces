#include <algorithm>
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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& b)
{
    const size_t n = b.size() / 2;

    std::sort(b.begin(), b.end(), std::greater<unsigned>());

    std::vector<integer> a(2 * n + 1);
    {
        integer p = 0;
        for (size_t i = 0; i <= n; ++i) {
            a[2*i] = b[i];
            p += b[i];
        }

        integer q = 0;
        for (size_t i = 1; i < n; ++i) {
            a[2*i+1] = b[n+i];
            q += b[n+i];
        }

        a[1] = p - q;
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(2 * n);
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
