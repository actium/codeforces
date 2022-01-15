#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& u, const std::vector<unsigned>& s)
{
    const size_t n = u.size();

    std::vector<std::vector<integer>> p(n);
    for (size_t i = 0; i < n; ++i)
        p[u[i]-1].push_back(s[i]);

    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i].empty()) {
            p[i--].swap(p.back());
            p.pop_back();
        } else {
            std::sort(p[i].begin(), p[i].end(), std::greater<integer>());

            for (size_t j = 1; j < p[i].size(); ++j)
                p[i][j] += p[i][j-1];
        }
    }

    std::vector<integer> r(n);
    for (size_t k = 1; k <= n; ++k) {
        for (size_t i = 0; i < p.size(); ++i) {
            if (p[i].size() < k) {
                p[i--].swap(p.back());
                p.pop_back();
            } else {
                const size_t m = p[i].size(), d = m % k;
                r[k-1] += p[i][m-1 - d];
            }
        }
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> u(n), s(n);
    std::cin >> u >> s;

    solve(u, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
