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

void solve(const std::vector<unsigned>& v, const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    std::vector<integer> p(1 + n), r(n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + t[i];

    std::vector<int> d(n);
    for (size_t i = 0; i < n; ++i) {
        ++d[i];

        const size_t x = std::upper_bound(p.begin(), p.end(), p[i] + v[i]) - p.begin() - 1;
        if (x < n) {
            --d[x];
            r[x] += v[i] - (p[x] - p[i]);
        }
    }

    integer c = 0;
    for (size_t i = 0; i < n; ++i) {
        c += d[i];
        r[i] += c * t[i];
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> v(n), t(n);
    std::cin >> v >> t;

    solve(v, t);

    return 0;
}
