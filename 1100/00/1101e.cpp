#include <iostream>
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
    unsigned x;
    unsigned y;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.x >> q.y;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<Query>& r)
{
    std::pair<unsigned, unsigned> c = { 0, 0 };
    for (const Query& q : r) {
        const unsigned x = std::min(q.x, q.y), y = std::max(q.x, q.y);
        if (q.t == '+') {
            c.first = std::max(c.first, x);
            c.second = std::max(c.second, y);
        } else {
            answer(c.first <= x && c.second <= y);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Query> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
