#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& x : v) 
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (k < n || k >= 2 * n)
        return no_answer();

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        const size_t r = (i <= k - n ? 0 : i);
        a[r][i] = 1 + i;
    }
    for (size_t i = 0, c = n; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (a[i][j] == 0)
                a[i][j] = ++c;
        }
    }

    answer(a);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
