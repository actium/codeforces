#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::string>& b)
{
    constexpr char t[2] = { 'W', 'B' };

    const size_t n = b.size(), m = b[0].length();

    std::vector<unsigned> c(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == 'L') {
                b[i][j+0] = t[c[j]];
                c[j] ^= 1;
                b[i][j+1] = t[c[j]];
            }
        }
    }

    for (const unsigned x : c) {
        if (x == 1)
            return no_answer();
    }

    std::vector<unsigned> r(n);
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 0; i < n; ++i) {
            if (b[i][j] == 'U') {
                b[i+0][j] = t[r[i]];
                r[i] ^= 1;
                b[i+1][j] = t[r[i]];
            }
        }
    }

    for (const unsigned x : r) {
        if (x == 1)
            return no_answer();
    }

    answer(b);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);
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
