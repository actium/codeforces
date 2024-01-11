#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n == 1)
        return k == 0 ? answer({1}) : no_answer();

    const unsigned q = n / 2;
    if (q > k)
        return no_answer();

    std::vector<unsigned> a(n);
    a[0] = k - q + 1;
    a[1] = a[0] * 2;
    for (size_t i = 2; i < n; ++i)
        a[i] = a[i-1] + 1;

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
