#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& a)
{
    const size_t n = p.size();

    std::vector<size_t> x(1+n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    for (size_t i = 1; i < n; ++i) {
        if (x[a[i-1]] > x[a[i]])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), a(n);
    std::cin >> p >> a;

    solve(p, a);
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
