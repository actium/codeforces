#include <iostream>
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

char label(size_t k)
{
    return k > 52 ? '0' + k - 53 : k > 26 ? 'a' + k - 27 : 'A' + k - 1;
}

void solve(std::vector<std::string>& b, size_t k)
{
    const size_t n = b.size(), m = b[0].size();

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            c += (b[i][j] == 'R');
    }

    for (size_t i = 0, j = 0, x = 1; i < n; --k) {
        unsigned d = c / k + (c % k != 0);
        c -= d;

        while (i < n && (d != 0 || b[i][j] != 'R')) {
            d -= (b[i][j] == 'R');
            b[i][j] = label(k);

            if (x == 1 && ++j == m || x == 0 && j-- == 0) {
                ++i;
                x ^= 1;
            }
            if (x == 1 && ~j == 0)
                j = 0;
        }
    }

    answer(b);
}

void test_case()
{
    size_t r, c, k;
    std::cin >> r >> c >> k;

    std::vector<std::string> b(r);
    std::cin >> b;

    solve(b, k);
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
