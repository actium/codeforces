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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> b[2];
    for (const unsigned x : a)
        b[x%2].push_back(x);

    std::vector<integer> v(n);
    if (!b[1].empty()) {
        std::sort(b[0].begin(), b[0].end(), std::greater<integer>());

        const size_t m = b[0].size();
        for (size_t j = 1; j < m; ++j)
            b[0][j] += b[0][j-1];

        v[0] = *std::max_element(b[1].begin(), b[1].end());

        for (size_t i = 0; i < m; ++i)
            v[i+1] = v[0] + b[0][i];

        for (size_t u = 2; u < b[1].size(); u += 2) {
            v[m+u] = v[m];

            if (m != 0)
                v[m+u-1] = v[m-1];
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
