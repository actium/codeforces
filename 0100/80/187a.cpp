#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& q)
{
    const size_t n = p.size();

    std::vector<size_t> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        x[q[i]] = i;

    size_t i = 1;
    while (i < n && x[p[i-1]] < x[p[i]])
        ++i;

    answer(n - i);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), q(n);
    std::cin >> p >> q;

    solve(p, q);

    return 0;
}
