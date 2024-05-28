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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, size_t m, const std::vector<unsigned>& a)
{
    std::vector<std::pair<unsigned, size_t>> q(n * m);
    for (size_t i = 0; i < n * m; ++i) {
        q[i].first = a[i];
        q[i].second = i;
    }

    std::sort(q.begin(), q.end());

    unsigned k = 0;
    for (auto it = q.begin(); it != q.end(); it += m) {
        std::sort(it, it + m, [](const auto& lhs, const auto& rhs) {
            return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second > rhs.second;
        });

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < i; ++j)
                k += (it[j].second < it[i].second);
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n * m);
    std::cin >> a;

    solve(n, m, a);
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
