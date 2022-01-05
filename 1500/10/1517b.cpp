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
    for (const std::vector<unsigned>& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(std::vector<std::vector<unsigned>>& b)
{
    const size_t n = b.size(), m = b[0].size();

    for (auto& v : b)
        std::sort(v.begin(), v.end(), std::greater<unsigned>());

    std::vector<std::vector<unsigned>> s(n, std::vector<unsigned>(m, ~0u));
    for (size_t j = 0; j < m; ++j) {
        size_t r = 0;
        for (size_t i = 1; i < n; ++i) {
            if (b[i].back() < b[r].back())
                r = i;
        }

        s[r][j] = b[r].back();
        b[r].pop_back();
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == ~0u) {
                s[i][j] = b[i].back();
                b[i].pop_back();
            }
        }
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> b(n, std::vector<unsigned>(m));
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
