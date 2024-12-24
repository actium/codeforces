#include <algorithm>
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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a, std::vector<unsigned>& q)
{
    const size_t m = a.size(), k = q.size();

    std::string s(m, '0' + (k == n));
    if (k == n - 1) {
        std::sort(q.begin(), q.end());

        for (size_t i = 0; i < m; ++i)
            s[i] += !std::binary_search(q.begin(), q.end(), a[i]);
    }

    answer(s);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(m), q(k);
    std::cin >> a >> q;

    solve(n, a, q);
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
