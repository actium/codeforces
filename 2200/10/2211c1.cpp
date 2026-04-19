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

void solve(const std::vector<unsigned>& a, const std::vector<int>& b, size_t k)
{
    const size_t n = a.size(), m = n - k;

    for (size_t i = 0; i < m; ++i) {
        if (b[i] != -1 && a[i] != b[i])
            return answer(false);
    }
    for (size_t i = n - m; i < n; ++i) {
        if (b[i] != -1 && a[i] != b[i])
            return answer(false);
    }

    std::vector<bool> q(1 + n);
    for (size_t i = m; i < n - m; ++i)
        q[a[i]] = true;

    for (size_t i = m; i < n - m; ++i) {
        if (b[i] == -1)
            continue;

        if (!q[b[i]])
            return answer(false);

        q[b[i]] = false;
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<int> b(n);
    std::cin >> b;

    solve(a, b, k);
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
