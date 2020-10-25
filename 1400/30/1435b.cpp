#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& x : v) {
        const char* separator = "";
        for (const unsigned y : x) {
            std::cout << separator << y;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(const std::vector<std::vector<unsigned>>& r, const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = r.size();
    const size_t m = c.size();

    const auto x = [&](size_t y) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t i = 0; i < n; ++i) {
                if (c[j][i] == r[y][0])
                    return i;
            }
        }
        return n;
    };

    std::vector<std::vector<unsigned>> z = r;
    for (size_t i = 0; i < n; ++i)
        z[x(i)] = r[i];

    answer(z);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> r(n, std::vector<unsigned>(m));
    std::cin >> r;

    std::vector<std::vector<unsigned>> c(m, std::vector<unsigned>(n));
    std::cin >> c;

    solve(r, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

