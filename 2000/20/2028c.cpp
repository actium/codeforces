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

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned m, unsigned v)
{
    const size_t n = a.size();

    const auto prepare = [&](auto it) {
        std::vector<unsigned> q(1+n);
        {
            unsigned s = 0;
            for (size_t i = 0; i < n; ++i) {
                s += *it++;
                if (s < v) {
                    q[i+1] = q[i];
                } else {
                    q[i+1] = q[i] + 1;
                    s = 0;
                }
            }
        }
        return q;
    };

    const std::vector<unsigned> p = prepare(a.begin()), s = prepare(a.rbegin());
    if (p[n] < m)
        return no_answer();

    std::vector<integer> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    integer w = 0;
    for (size_t i = 0, j = n; i < n; ++i) {
        while (j > 0 && p[i] + s[j-1] >= m)
            --j;

        if (i < n-j)
            w = std::max(w, ps[n-j] - ps[i]);
    }

    answer(w);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, v;
    std::cin >> m >> v;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, v);
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
