#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<bool> u(1+n), v(1+n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i] != 1 + i)
            u[p[i]] = true;

        if (p[i] != n - i)
            v[p[i]] = true;
    }

    unsigned f[3] = {};
    for (size_t i = 1; i <= n; ++i) {
        f[0] += (u[i] && !v[i]);
        f[1] += (u[i] && v[i]);
        f[2] += (!u[i] && v[i]);
    }

    if (f[0] + f[1] <= f[2])
        return answer("First");

    if (f[2] + f[1] < f[0])
        return answer("Second");

    answer("Tie");
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
