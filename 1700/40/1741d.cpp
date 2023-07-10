#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct Node {
    unsigned lb;
    unsigned ub;
    bool ordered;
    unsigned k;
};

Node traverse(const std::vector<unsigned>& p, size_t lb, size_t ub)
{
    const size_t k = (ub - lb) / 2;
    if (k == 0)
        return { p[lb], p[lb], true, 0 };

    const Node l = traverse(p, lb, lb + k);
    if (!l.ordered || l.ub - l.lb + 1 != k)
        return { 0, 0, false, 0 };

    const Node r = traverse(p, lb + k, ub);
    if (!r.ordered || r.ub - r.lb + 1 != k)
        return { 0, 0, false, 0 };

    return { std::min(l.lb, r.lb), std::max(l.ub, r.ub), true, l.k + r.k + (r.lb < l.lb) };
}

void solve(const std::vector<unsigned>& p)
{
    const Node x = traverse(p, 0, p.size());

    x.ordered ? answer(x.k) : no_answer();
}

void test_case()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> p(m);
    std::cin >> p;

    solve(p);
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
