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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<size_t> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (a[i] <= k);

    // x *** y
    for (size_t x = 1, y = 1; x + y < n; ) {
        if (2 * p[x] < x) {
            ++x;
            continue;
        }
        if (2 * (p[n] - p[n-y]) < y) {
            ++y;
            continue;
        }
        return answer(true);
    }

    // x y ***
    for (size_t x = 1; x < n; ++x) {
        if (2 * p[x] < x)
            continue;

        for (size_t y = 1; x + y < n; ++y) {
            if (2 * (p[x+y] - p[x]) >= y)
                return answer(true);
        }
    }

    // *** x y
    for (size_t y = 1; y < n; ++y) {
        if (2 * (p[n] - p[n-y]) < y)
            continue;

        for (size_t x = 1; x + y < n; ++x) {
            if (2 * (p[n-y] - p[n-y-x]) >= x)
                return answer(true);
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
