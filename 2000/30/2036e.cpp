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

struct Query {
    unsigned r;
    char o;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.r >> q.o >> q.c;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a, const std::vector<std::vector<Query>>& r)
{
    const size_t n = a.size(), k = a[0].size();

    std::vector<std::vector<unsigned>> b(k, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j)
            b[j][i] = (i != 0 ? b[j][i-1] | a[i][j] : a[i][j]);
    }

    for (const std::vector<Query>& v : r) {
        size_t lb = 0, ub = n;
        for (const Query& q : v) {
            const std::vector<unsigned>& s = b[q.r-1];

            if (q.o == '<') {
                const auto it = std::lower_bound(s.begin(), s.end(), q.c);
                if (it != s.begin()) {
                    ub = std::min<size_t>(ub, it - s.begin() - 1);
                    continue;
                }
            } else {
                const auto it = std::upper_bound(s.begin(), s.end(), q.c);
                if (it != s.end()) {
                    lb = std::max<size_t>(lb, it - s.begin());
                    continue;
                }
            }

            lb = ub + 1;
            break;
        }

        lb <= ub ? answer(lb + 1) : no_answer();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k, q;
    std::cin >> n >> k >> q;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(k));
    std::cin >> a;

    std::vector<std::vector<Query>> r(q);
    for (size_t i = 0; i < q; ++i) {
        size_t m;
        std::cin >> m;

        r[i].resize(m);
        std::cin >> r[i];
    }

    solve(a, r);

    return 0;
}
