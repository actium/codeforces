#include <iomanip>
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

void answer(double x)
{
    std::cout << std::fixed << std::setprecision(10) << x << '\n';
}

void solve(const std::vector<unsigned>& x, const std::vector<Edge>& e)
{
    double d = 0;
    for (const Edge& q : e)
        d = std::max(d, double(x[q.a-1] + x[q.b-1]) / q.c);

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::vector<Edge> e(m);
    std::cin >> e;

    solve(x, e);

    return 0;
}
