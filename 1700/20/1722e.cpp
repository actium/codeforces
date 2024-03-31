#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned hs;
    unsigned ws;
    unsigned hb;
    unsigned wb;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.hs >> q.ws >> q.hb >> q.wb;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& r, const std::vector<Query>& s)
{
    std::vector<std::vector<integer>> c(1001, std::vector<integer>(1001));
    for (const std::pair<unsigned, unsigned>& p : r)
        c[p.first][p.second] += p.first * p.second;

    for (unsigned h = 1; h <= 1000; ++h) {
        for (unsigned w = 1; w <= 1000; ++w) {
            c[h][w] += c[h-1][w];
            c[h][w] += c[h][w-1];
            c[h][w] -= c[h-1][w-1];
        }
    }

    for (const Query& q : s)
        answer(c[q.hb-1][q.wb-1] - c[q.hb-1][q.ws] - c[q.hs][q.wb-1] + c[q.hs][q.ws]);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    std::vector<Query> s(q);
    std::cin >> s;

    solve(r, s);
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