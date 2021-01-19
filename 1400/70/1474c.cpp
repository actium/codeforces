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

std::vector<std::pair<unsigned, unsigned>> check(const std::vector<unsigned>& a, unsigned x, std::vector<unsigned>& f)
{
    std::vector<std::pair<unsigned, unsigned>> p;
    const auto rollback = [&] {
        for (const auto& q : p)
            ++f[q.first], ++f[q.second];

        p.clear();
    };

    for (const unsigned q : a) {
        if (f[q] == 0)
            continue;

        const unsigned c = x - q;
        if (f[c] <= (c == q)) {
            rollback();
            break;
        }

        p.emplace_back(c, q);
        --f[c], --f[q];
        x = q;
    }

    return p;
}

void answer(unsigned x, const std::vector<std::pair<unsigned, unsigned>>& y)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';

    for (const auto& p : y)
        std::cout << p.first << ' ' << p.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    static std::vector<unsigned> f;
    f.assign(1 + a[0], 0);
    for (const unsigned x : a)
        ++f[x];

    for (size_t i = 1; i < n; ++i) {
        const auto v = check(a, a[0] + a[i], f);
        if (!v.empty())
            return answer(a[0] + a[i], v);
    }

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

