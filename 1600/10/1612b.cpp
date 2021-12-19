#include <algorithm>
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

void solve(unsigned n, unsigned a, unsigned b)
{
    std::vector<unsigned> p;
    p.reserve(n);

    p.push_back(a);
    for (unsigned x = n; x > 0; --x) {
        if (x != a && x != b)
            p.push_back(x);
    }
    p.push_back(b);

    if (*std::min_element(p.begin(), p.begin() + n / 2) < a)
        return no_answer();
    if (*std::max_element(p.begin() + n / 2, p.end()) > b)
        return no_answer();

    answer(p);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
