#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<unsigned>& v)
{
    std::cout << "Yes" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(size_t n, integer k)
{
    if (k % 2 == 1)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i + 1;

    for (size_t i = 0, j = n-1; i < j && k != 0; ++i) {
        const unsigned d = p[j] - p[i];
        if (2 * d <= k) {
            k -= 2 * d;
            std::swap(p[i], p[j--]);
        }
    }

    k == 0 ? answer(p) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    solve(n, k);
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
