#include <iostream>
#include <set>
#include <vector>

using position_t = std::pair<unsigned, unsigned>;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const position_t& s, const position_t& t)
{
    const size_t n = a.size();

    std::set<position_t> v;
    std::vector<position_t> q;

    const auto enqueue = [&](unsigned r, unsigned c) {
        if (r < 1 || r > n || c < 1)
            return;

        c = std::min(c, a[r-1] + 1);

        if (v.emplace(r, c).second)
            q.emplace_back(r, c);
    };

    unsigned d = ~0u;
    {
        enqueue(s.first, s.second);
        for (unsigned k = 0; !q.empty(); ++k) {
            std::vector<position_t> r;
            std::swap(q, r);

            for (const position_t& p : r) {
                if (p.first == t.first)
                    d = std::min(d, k + std::max(p.second, t.second) - std::min(p.second, t.second));

                enqueue(p.first - 1, p.second);
                enqueue(p.first + 1, p.second);
            }
        }
    }

    answer(d);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    position_t s, t;
    std::cin >> s >> t;

    solve(a, s, t);

    return 0;
}
