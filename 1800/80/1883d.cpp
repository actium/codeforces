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
    char t;
    unsigned l;
    unsigned r;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.l >> q.r;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<Query>& r)
{
    std::multiset<unsigned> s, t;
    for (const Query& q : r) {
        if (q.t == '+') {
            s.insert(q.r);
            t.insert(q.l);
        } else {
            s.erase(s.find(q.r));
            t.erase(t.find(q.l));
        }

        answer(s.size() >= 2 && *s.begin() < *t.rbegin());
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(r);

    return 0;
}
