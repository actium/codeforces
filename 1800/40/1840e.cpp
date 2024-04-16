#include <iostream>
#include <queue>
#include <string>
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
        unsigned p;

        struct {
            unsigned x1;
            unsigned p1;
            unsigned x2;
            unsigned p2;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;

    if (q.t == 1)
        input >> q.p;

    if (q.t == 2)
        input >> q.x1 >> q.p1 >> q.x2 >> q.p2;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s1, std::string& s2, unsigned t, const std::vector<Query>& r)
{
    const size_t n = s1.length(), m = r.size();

    unsigned d = 0;
    for (size_t i = 0; i < n; ++i)
        d += (s1[i] != s2[i]);

    std::queue<std::pair<unsigned, size_t>> b;
    for (size_t i = 0; i < m; ++i) {
        while (!b.empty() && b.front().first + t == i) {
            const size_t x = b.front().second;
            d += (s1[x] != s2[x]);
            b.pop();
        }

        if (r[i].t == 1) {
            const size_t x = r[i].p - 1;
            d -= (s1[x] != s2[x]);
            b.emplace(i, x);
        }

        if (r[i].t == 2) {
            const size_t x1 = r[i].p1 - 1, x2 = r[i].p2 - 1;

            d -= (s1[x1] != s2[x1]);
            d -= (s1[x2] != s2[x2]);

            std::swap((r[i].x1 == 1 ? s1 : s2)[x1], (r[i].x2 == 1 ? s1 : s2)[x2]);

            d += (s1[x1] != s2[x1]);
            d += (s1[x2] != s2[x2]);
        }

        if (r[i].t == 3)
            answer(d == 0);
    }
}

void test_case()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    unsigned t;
    std::cin >> t;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(s1, s2, t, r);
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
