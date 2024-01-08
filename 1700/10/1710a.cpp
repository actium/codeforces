#include <algorithm>
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

bool check(size_t n, size_t m, const std::vector<unsigned>& a)
{
    unsigned k = 0, c = 0;
    for (const unsigned q : a) {
        const unsigned d = q / n;
        if (d < 2 || d == 2 && k + d == m - 1 && c == 0)
            continue;

        if (k + d >= m)
            return true;

        k += d;
        c += (d > 2);
    }

    return false;
}

void solve(size_t n, size_t m, std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    answer(check(n, m, a) || check(m, n, a));
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, m, a);
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
