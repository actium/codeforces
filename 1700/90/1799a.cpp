#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<unsigned>& p)
{
    const size_t m = p.size();

    std::vector<int> t(n, -1);
    std::vector<bool> v(m);
    for (size_t i = 0, j = n; i < m; ++i) {
        const size_t x = p[i] - n;
        if (v[x])
            continue;

        if (j > 0)
            t[--j] = 1 + i;

        v[x] = true;
    }

    answer(t);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> p(m);
    std::cin >> p;

    solve(n, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
