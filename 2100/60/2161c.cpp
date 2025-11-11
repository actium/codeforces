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

void answer(integer u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, unsigned x)
{
    std::sort(a.begin(), a.end());

    integer t = 0, v = 0;

    std::vector<unsigned> b;
    for (size_t i = 0, j = a.size() - 1; ~j != 0 && i <= j; ) {
        if (a[j] >= x - t % x) {
            v += a[j];
            t += a[j];
            b.push_back(a[j--]);
        } else {
            t += a[i];
            b.push_back(a[i++]);
        }
    }

    answer(v, b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
