#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

struct Node {
    unsigned a = 0;
    unsigned b = 0;

    std::vector<size_t> subnodes;
};

void traverse(const std::vector<Node>& t, size_t u, integer a, std::vector<integer>& q, std::vector<unsigned>& r)
{
    a += t[u].a;
    q.push_back(q.back() + t[u].b);

    r[u] = std::upper_bound(q.begin(), q.end(), a) - q.begin() - 2;

    for (const size_t v : t[u].subnodes)
        traverse(t, v, a, q, r);

    q.pop_back();
    a -= t[u].a;
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

void solve(const std::vector<Node>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> r(n);
    {
        std::vector<integer> q(1);
        traverse(t, 0, 0, q, r);
    }

    r.erase(r.begin());

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<Node> t(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned p;
        std::cin >> p >> t[i].a >> t[i].b;

        t[p-1].subnodes.push_back(i);
    }

    solve(t);
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
