#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<integer>& x, const std::vector<integer>& p)
{
    const size_t n = x.size(), m = p.size();

    integer d = 0;
    for (size_t i = 1; i < n; ++i)
        d = std::gcd(d, x[i] - x[i-1]);

    for (size_t i = 0; i < m; ++i) {
        if (d % p[i] == 0)
            return answer(x[0], 1+i);
    }

    no_answer();
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<integer> x(n);
    std::cin >> x;

    std::vector<integer> p(m);
    std::cin >> p;

    solve(x, p);

    return 0;
}

