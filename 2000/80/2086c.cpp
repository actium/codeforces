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

unsigned count(std::vector<unsigned>& p, size_t x)
{
    if (p[x] == 0)
        return 0;

    const size_t v = p[x] - 1;
    p[x] = 0;
    if (v != x)
        return count(p, v) + 1;

    return 1;
}

void solve(std::vector<unsigned>& p, const std::vector<unsigned>& d)
{
    const size_t n = p.size();

    std::vector<unsigned> c(n);
    c[0] = count(p, d[0] - 1);
    for (size_t i = 1; i < n; ++i)
        c[i] = c[i-1] + count(p, d[i] - 1);

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), d(n);
    std::cin >> p >> d;

    solve(p, d);
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
