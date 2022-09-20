#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

struct Segment {
    integer p;
    integer k;
    integer l;
};

size_t resolve(const std::vector<Segment>& p, integer x)
{
    while (x >= p[0].k) {
        const auto it = std::upper_bound(p.cbegin(), p.cend(), x, [](integer x, const Segment& s) {
            return s.p + s.k > x;
        });

        x = it->l + (x - it->p);
    }
    return x;
}

void answer(char x)
{
    std::cout << x << '\n';
}

void test_case()
{
    size_t n, c, q;
    std::cin >> n >> c >> q;

    std::string s;
    std::cin >> s;

    std::vector<Segment> p;
    p.push_back({ 0, n, 0 });
    for (size_t i = 0; i < c; ++i) {
        integer l, r;
        std::cin >> l >> r;

        p.push_back({ p.back().p + p.back().k, r - l + 1, l - 1 });
    }

    for (size_t i = 0; i < q; ++i) {
        integer x;
        std::cin >> x;

        answer(s[resolve(p, x-1)]);
    }
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
