#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<unsigned> s;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            s.push_back(a[i]);
    }

    if (s.size() != n % 2)
        return no_answer();

    std::vector<size_t> x(1+n);
    for (size_t i = 0; i < n; ++i)
        x[b[i]] = i;

    std::vector<std::pair<size_t, size_t>> ops;

    const auto swap = [&](size_t i, size_t j) {
        if (i != j) {
            const unsigned u = b[i], v = b[j];

            std::swap(a[i], a[j]);
            std::swap(b[i], b[j]);
            std::swap(x[u], x[v]);

            ops.emplace_back(i, j);
        }
    };

    if (!s.empty())
        swap(x[s.front()], n / 2);

    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[n-1-i])
            continue;

        const size_t j = x[a[i]];
        if (j < i)
            return no_answer();

        swap(j, n-1-i);
    }

    answer(ops);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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