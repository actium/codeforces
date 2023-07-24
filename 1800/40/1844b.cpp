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

void solve(unsigned n)
{
    std::vector<unsigned> v(n);
    for (unsigned i = 1; i <= n; ++i)
        v[i-1] = i;

    if (n < 3)
        return answer(v);

    std::swap(v[1], v[0]);
    std::swap(v[2], v[n-1]);
    std::swap(v[1], v[n/2]);

    answer(v);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
