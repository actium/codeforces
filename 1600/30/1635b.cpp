#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 2; i < n; ++i) {
        if (a[i-1] <= a[i-2] || a[i-1] <= a[i])
            continue;

        if (i + 1 == n) {
            a[i-1] = a[i-2];
        } else {
            a[i] = std::max(a[i-1], a[i+1]);
        }

        ++k;
    }

    answer(k, a);
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

