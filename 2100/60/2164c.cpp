#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    const size_t m = b.size();

    unsigned k = 0;
    {
        std::multiset<std::pair<unsigned, unsigned>> q;
        for (size_t i = 0; i < m; ++i) {
            if (c[i] != 0)
                q.emplace(b[i], c[i]);
        }

        std::multiset<unsigned> p(a.begin(), a.end());
        for (const auto& e : q) {
            if (e.first <= *p.rbegin()) {
                const auto it = p.lower_bound(e.first);
                if (e.second > *it) {
                    p.erase(it);
                    p.insert(e.second);
                }
                ++k;
            }
        }

        for (size_t i = 0; i < m; ++i) {
            if (c[i] != 0)
                continue;

            const auto it = p.lower_bound(b[i]);
            if (it != p.end()) {
                p.erase(it);
                ++k;
            }
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m), c(m);
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned t;
    std::cin >> t;

    while (t-- != 0)
        test_case();

    return 0;
}
