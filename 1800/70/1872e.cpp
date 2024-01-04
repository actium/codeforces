#include <iostream>
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
        struct {
            unsigned l;
            unsigned r;
        };
        unsigned g;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.l >> q.r : input >> q.g;
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

void solve(const std::vector<unsigned>& a, const std::string& s, const std::vector<Query>& r)
{
    const size_t n = a.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] ^ a[i];

    unsigned x[2] = {};
    for (size_t i = 0; i < n; ++i)
        x[s[i]-'0'] ^= a[i];

    std::vector<unsigned> v;
    for (const Query& q : r) {
        if (q.t == 1) {
            x[0] ^= ps[q.r] ^ ps[q.l-1];
            x[1] ^= ps[q.r] ^ ps[q.l-1];
        } else {
            v.push_back(x[q.g]);
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(a, s, r);
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
