#include <iostream>
#include <vector>

struct Constraint {
    size_t l;
    size_t r;
    size_t x;
};

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t h, const std::vector<Constraint>& constraints)
{
    std::vector<size_t> z(n, h);
    for (const Constraint& c : constraints) {
        for (size_t i = c.l - 1; i < c.r; ++i) {
            z[i] = std::min(z[i], c.x);
        }
    }

    size_t s = 0;
    for (const size_t a : z)
        s += a * a;

    answer(s);
}

int main()
{
    size_t n, h, m;
    std::cin >> n >> h >> m;

    std::vector<Constraint> constraints(m);
    for (Constraint& c : constraints)
        std::cin >> c.l >> c.r >> c.x;

    solve(n, h, constraints);

    return 0;
}

