#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;

    union {
        unsigned s;
        struct {
            unsigned i;
            unsigned v;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.s : input >> q.i >> q.v;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<Query>& r)
{
    const size_t n = a.size();

    std::set<size_t> x;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 1)
            x.insert(i);
    }

    unsigned s = x.size() + (n - x.size()) * 2;
    for (const Query& q : r) {
        if (q.t == 2) {
            if (a[q.i-1] == 1)
                x.erase(q.i-1);

            s -= a[q.i-1];
            a[q.i-1] = q.v;
            s += a[q.i-1];

            if (a[q.i-1] == 1)
                x.insert(q.i-1);
        } else {
            if (q.s > s) {
                answer(false);
                continue;
            }
            if (q.s % 2 == s % 2) {
                answer(true);
                continue;
            }
            if (x.empty()) {
                answer(false);
                continue;
            }
            answer(q.s + 2 * std::min(*x.begin(), n - 1 - *x.rbegin()) <= s);
        }
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(a, r);
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
