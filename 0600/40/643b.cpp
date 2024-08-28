#include <iostream>
#include <vector>

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k, unsigned a, unsigned b, unsigned c, unsigned d)
{
    if (n == 4 || k <= n)
        return no_answer();

    std::vector<unsigned> p(n);
    p[0] = a;
    p[1] = c;
    for (size_t i = 2, x = 1; i < n-2; ++i) {
        while (x == a || x == b || x == c || x == d)
            ++x;

        p[i] = x++;
    }
    p[n-2] = d;
    p[n-1] = b;

    std::vector<unsigned> q = p;
    std::swap(q[0], q[1]);
    std::swap(q[n-2], q[n-1]);

    answer(p, q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(n, k, a, b, c, d);

    return 0;
}
