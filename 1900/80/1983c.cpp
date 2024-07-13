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

void answer(const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y, const std::pair<unsigned, unsigned>& z)
{
    std::cout << x.first << ' ' << x.second << ' ' << y.first << ' ' << y.second << ' ' << z.first << ' ' << z.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<integer>& a, std::vector<integer>& b, std::vector<integer>& c)
{
    const size_t n = a.size();

    const std::vector<integer>* v[3] = { &a, &b, &c };

    for (size_t i = 1; i < n; ++i) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        c[i] += c[i-1];
    }

    const integer t = a.back(), s = (t + 2) / 3;

    std::vector<size_t> p = { 0, 1, 2 };
    do {
        const size_t di = std::lower_bound(v[p[0]]->begin(), v[p[0]]->end(), s) - v[p[0]]->begin();
        if (di == n)
            continue;

        const size_t dj = std::lower_bound(v[p[1]]->begin() + di + 1, v[p[1]]->end(), (*v[p[1]])[di] + s) - v[p[1]]->begin();
        if (dj == n)
            continue;

        if (t - (*v[p[2]])[dj] >= s) {
            std::pair<unsigned, unsigned> bounds[3];
            bounds[p[0]] = { 1, di + 1 };
            bounds[p[1]] = { di + 2, dj + 1 };
            bounds[p[2]] = { dj + 2, n };
            return answer(bounds[0], bounds[1], bounds[2]);
        }
    } while (std::next_permutation(p.begin(), p.end()));

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n), b(n), c(n);
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
