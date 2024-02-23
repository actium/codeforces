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

void solve(const std::vector<int>& x, const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> d(1 + n);
    for (size_t i = 0; i < n; ++i)
        d[abs(x[i])] += a[i];

    unsigned long long r = 0;
    for (size_t i = 1; i <= n; ++i) {
        r += k;
        if (r < d[i])
            return answer(false);

        r -= d[i];
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x, a, k);
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
