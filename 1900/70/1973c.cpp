#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    std::vector<unsigned> q(n);
    for (unsigned i = 1, u = n / 2, v = n; i <= n; ++i) {
        if (x[i] % 2 == x[1] % 2)
            q[x[i]] = u--;
        else
            q[x[i]] = v--;
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
