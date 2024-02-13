#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Edge {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Edge& e)
{
    return input >> e.a >> e.b >> e.c;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& q, std::vector<Edge>& e)
{
    const size_t n = q.size();

    std::sort(e.begin(), e.end(), [](const Edge& lhs, const Edge& rhs) {
        return lhs.c < rhs.c;
    });

    std::vector<unsigned> p(n);

    unsigned c = 0;
    for (const Edge& x : e) {
        if (p[x.b-1] == 0) {
            p[x.b-1] = x.a;
            c += x.c;
        }
    }

    if (std::count(p.begin(), p.end(), 0) == 1)
        answer(c);
    else
        no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> q(n);
    std::cin >> q;

    size_t m;
    std::cin >> m;

    std::vector<Edge> e(m);
    std::cin >> e;

    solve(q, e);

    return 0;
}
