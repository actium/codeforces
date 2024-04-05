#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

struct Node {
    unsigned b;
    unsigned e;
    integer s;
};

bool operator <(const Node& lhs, const Node& rhs)
{
    if (lhs.s != rhs.s)
        return lhs.s < rhs.s;

    return std::make_pair(lhs.b, lhs.e) < std::make_pair(rhs.b, rhs.e);
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& p)
{
    const size_t n = a.size();

    std::vector<integer> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    std::set<std::pair<unsigned, unsigned>> s;
    std::set<Node> t;

    const auto insert = [&](unsigned b, unsigned e) {
        if (b <= e) {
            s.emplace(e, b);
            t.insert({ b, e, ps[e] - ps[b-1] });
        }
    };

    const auto remove = [&](unsigned b, unsigned e) {
        s.erase(std::make_pair(e, b));
        t.erase({ b, e, ps[e] - ps[b-1] });
    };

    insert(1, n);
    for (const unsigned x : p) {
        const auto [e, b] = *s.lower_bound(std::make_pair(x, 0));

        remove(b, e);
        insert(b, x - 1);
        insert(x + 1, e);

        answer(t.empty() ? 0 : t.rbegin()->s);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), p(n);
    std::cin >> a >> p;

    solve(a, p);

    return 0;
}
