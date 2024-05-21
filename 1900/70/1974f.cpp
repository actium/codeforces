#include <iostream>
#include <set>
#include <vector>

using spot_t = std::pair<unsigned, unsigned>;
using turn_t = std::pair<char, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned h, unsigned w, const std::vector<spot_t>& p, const std::vector<turn_t>& q)
{
    const size_t n = p.size(), m = q.size();

    std::set<spot_t> r, c;
    for (size_t i = 0; i < n; ++i) {
        r.emplace(p[i].first, p[i].second);
        c.emplace(p[i].second, p[i].first);
    }

    unsigned d[4] = { 1, w, h, 1 }, v[2] = {};
    for (size_t i = 0, x = 0; i < m; ++i, x ^= 1) {
        if (q[i].first == 'U') {
            d[0] += q[i].second;

            while (!r.empty() && r.begin()->first < d[0]) {
                c.erase(std::make_pair(r.begin()->second, r.begin()->first));
                r.erase(r.begin());
                ++v[x];
            }
        }
        if (q[i].first == 'R') {
            d[1] -= q[i].second;

            while (!c.empty() && c.rbegin()->first > d[1]) {
                r.erase(std::make_pair(c.rbegin()->second, c.rbegin()->first));
                c.erase(std::prev(c.end()));
                ++v[x];
            }
        }
        if (q[i].first == 'D') {
            d[2] -= q[i].second;

            while (!r.empty() && r.rbegin()->first > d[2]) {
                c.erase(std::make_pair(r.rbegin()->second, r.rbegin()->first));
                r.erase(std::prev(r.end()));
                ++v[x];
            }
        }
        if (q[i].first == 'L') {
            d[3] += q[i].second;

            while (!c.empty() && c.begin()->first < d[3]) {
                r.erase(std::make_pair(c.begin()->second, c.begin()->first));
                c.erase(c.begin());
                ++v[x];
            }
        }
    }

    answer(v[0], v[1]);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    size_t n, m;
    std::cin >> n >> m;

    std::vector<spot_t> p(n);
    std::cin >> p;

    std::vector<turn_t> q(m);
    std::cin >> q;

    solve(a, b, p, q);
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
