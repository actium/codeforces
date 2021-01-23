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

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(std::vector<std::vector<unsigned>>& r, const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = r.size(), m = c.size();

    const auto row = [&](unsigned x) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t i = 0; i < n; ++i) {
                if (c[j][i] == x)
                    return i;
            }
        }
        return n;
    };

    const auto compare = [&](const std::vector<unsigned>& a, const std::vector<unsigned>& b) {
        return row(a[0]) < row(b[0]);
    };
    std::sort(r.begin(), r.end(), compare);

    answer(r);
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

