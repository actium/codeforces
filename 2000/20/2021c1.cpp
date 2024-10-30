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
    constexpr const char* s[2] = { "TIDAK", "YA" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<bool> v(1+n);
    for (size_t i = 0, j = 0; j < m; ++j) {
        if (i < n && b[j] == a[i]) {
            v[a[i]] = true;
            ++i;
        }

        if (!v[b[j]])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m, q;
    std::cin >> n >> m >> q;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
