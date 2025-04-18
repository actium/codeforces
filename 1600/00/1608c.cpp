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

std::vector<size_t> sort(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    {
        for (size_t i = 0; i < n; ++i)
            p[i] = i;

        std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
            return a[i] < a[j];
        });
    }
    return p;
}

std::vector<size_t> index(const std::vector<size_t>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    return x;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::string s(n, '0');
    {
        std::vector<size_t> p[2] = { sort(a), sort(b) }, r[2] = { index(p[0]), index(p[1]) };

        std::vector<std::pair<size_t, size_t>> q;
        q.emplace_back(1, p[0].back());
        while (!q.empty()) {
            const std::pair<size_t, size_t> e = q.back();
            q.pop_back();

            for (const size_t x = r[e.first][e.second]; p[e.first].size() > x; p[e.first].pop_back()) {
                s[p[e.first].back()] = '1';
                q.emplace_back(e.first^1, p[e.first].back());
            }
        }
    }
    answer(s);
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
