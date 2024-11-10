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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(const std::vector<std::string>& a, size_t d)
{
    const size_t n = a.size(), m = a[0].size();

    std::string q;
    for (size_t j = d+1; j < m-d; ++j)
        q.push_back(a[d][j]);
    for (size_t i = d+1; i < n-d; ++i)
        q.push_back(a[i][m-1-d]);
    for (size_t j = m-1-d; j > d; --j)
        q.push_back(a[n-1-d][j-1]);
    for (size_t i = n-1-d; i > d; --i)
        q.push_back(a[i-1][d]);

    q += q.substr(0, 4);

    unsigned v = 0, k = 0;
    for (size_t i = 0; i < q.size(); ++i) {
        k += (v == 1543);
        v = v % 1000 * 10 + q[i] - '0';
    }
    return k;
}

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size(), m = a[0].size();

    unsigned k = 0;
    for (size_t i = 0; i < std::min(m, n) / 2; ++i)
        k += count(a, i);

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
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
