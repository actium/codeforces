#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& a, unsigned m)
{
    std::multiset<unsigned> p(a.begin(), a.end());

    integer t = 0;
    {
        std::set<std::pair<integer, unsigned>> q;

        unsigned d = 0;

        const auto download = [&] {
            if (p.empty() || d != 0)
                return;

            auto it = p.upper_bound(m);
            if (it == p.begin())
                return;

            d = *--it;
            m -= d;
            q.emplace(t + d, 1);
            p.erase(it);
        };

        download();

        for (unsigned w = 0; !q.empty(); q.erase(q.begin())) {
            t = q.begin()->first;

            if (q.begin()->second == 0) {
                m += w;
            } else {
                w = d;
                d = 0;
                q.emplace(t + 1, 0);
            }

            download();
        }
    }
    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
