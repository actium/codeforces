#include <iostream>
#include <string>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<point_t, point_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<point_t, point_t>& x : v) {
        std::cout << x.first.first << ' ' << x.first.second << ' ';
        std::cout << x.second.first << ' ' << x.second.second << '\n';
    }
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].size();

    if (b[0][0] == '1')
        return no_answer();

    std::vector<std::pair<point_t, point_t>> q;
    for (unsigned i = n; i > 1; --i) {
        for (unsigned j = m; j > 0; --j) {
            if (b[i-1][j-1] == '1')
                q.emplace_back(point_t(i-1, j), point_t(i, j));
        }
    }
    for (unsigned j = m; j > 0; --j) {
        if (b[0][j-1] == '1')
            q.emplace_back(point_t(1, j-1), point_t(1, j));
    }

    answer(q);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
