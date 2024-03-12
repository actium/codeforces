#include <iostream>
#include <set>
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
            unsigned p;
            char c;
        };
        struct {
            unsigned l;
            unsigned r;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.p >> q.c : input >> q.l >> q.r;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, const std::vector<Query>& r)
{
    const size_t n = s.length();

    std::set<unsigned> p[26];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'].insert(i + 1);

    for (const Query& q : r) {
        if (q.t == 1) {
            p[s[q.p-1]-'a'].erase(q.p);
            s[q.p-1] = q.c;
            p[s[q.p-1]-'a'].insert(q.p);
        } else {
            unsigned k = 0;
            for (size_t i = 0; i < 26; ++i) {
                const auto it = p[i].lower_bound(q.l);
                if (it != p[i].end() && *it <= q.r)
                    ++k;
            }

            answer(k);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(s, r);

    return 0;
}
