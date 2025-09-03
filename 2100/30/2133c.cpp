#include <iostream>
#include <vector>

unsigned query(const std::vector<unsigned>& s)
{
    std::cout << '?' << ' ' << s[0] << ' ' << s.size();
    for (const unsigned p : s)
        std::cout << ' ' << p;

    std::cout << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << '!' << ' ' << v.size();
    for (const unsigned p : v)
        std::cout << ' ' << p;

    std::cout << std::endl;
}

void solve(unsigned n)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i + 1;

    std::vector<std::vector<unsigned>> h(1+n);
    for (size_t i = 0; i < n; ++i) {
        std::swap(p[0], p[i]);
        h[query(p)].push_back(p[0]);
        std::swap(p[0], p[i]);
    }

    size_t i = n;
    while (h[i].empty())
        --i;

    std::vector<unsigned> q = { h[i].back() };
    while (--i != 0) {
        for (const unsigned y : h[i]) {
            if (query({ q.back(), y }) == 2) {
                q.push_back(y);
                break;
            }
        }
    }

    answer(q);
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
