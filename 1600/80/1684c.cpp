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

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<size_t> p;
    for (size_t i = 0; i < n && p.empty(); ++i) {
        std::vector<unsigned> b = a[i];
        std::sort(b.begin(), b.end());

        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] != b[j])
                p.push_back(j);
        }
    }

    if (p.empty())
        return answer(0, 0);

    if (p.size() != 2)
        return no_answer();

    for (size_t i = 0; i < n; ++i) {
        std::swap(a[i][p.front()], a[i][p.back()]);

        for (size_t j = 1; j < m; ++j) {
            if (a[i][j] < a[i][j-1])
                return no_answer();
        }
    }

    answer(p.front(), p.back());
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);
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
