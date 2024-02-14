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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

std::vector<unsigned> restore(const std::vector<unsigned>& u, const std::vector<unsigned>& v)
{
    std::vector<unsigned> p(u.begin() + 1, u.end());

    const auto x = std::find(v.begin(), v.end(), u[0]);
    p.insert(std::find(p.begin(), p.end(), *(x - 1)) + 1, u[0]);
    return p;
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t k = a.size(), n = a[0].size();

    if (k == 1)
        return answer(true);

    const auto check = [n](const std::vector<unsigned>& q, const std::vector<unsigned>& p) {
        if (q[0] == p[0])
            return q == p;

        for (size_t i = 0, j = 1; i < n; ++i) {
            if (p[i] == q[0])
                continue;

            if (q[j] != p[i])
                return false;

            ++j;
        }
        return true;
    };

    const auto test = [&](const std::vector<unsigned>& u, const std::vector<unsigned>& v) {
        const std::vector<unsigned> p = restore(u, v);
        for (const std::vector<unsigned>& q : a) {
            if (!check(q, p))
                return false;
        }
        return true;
    };

    answer(test(a[0], a[1]) || test(a[1], a[0]));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::vector<unsigned>> a(k, std::vector<unsigned>(n));
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
