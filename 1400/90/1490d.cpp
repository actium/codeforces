#include <algorithm>
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

void build_tree(const std::vector<unsigned>& a, size_t lb, size_t ub, unsigned d, std::vector<unsigned>& v)
{
    if (lb == ub)
        return;

    const size_t x = std::max_element(a.cbegin() + lb, a.cbegin() + ub) - a.cbegin();
    v[x] = d;
    build_tree(a, lb, x, d+1, v);
    build_tree(a, x+1, ub, d+1, v);
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> v(n);
    build_tree(a, 0, n, 0, v);
    answer(v);
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
