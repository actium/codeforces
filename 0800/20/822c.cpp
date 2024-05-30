#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Tour {
    unsigned l;
    unsigned r;
    unsigned w;
};

std::istream& operator >>(std::istream& input, Tour& t)
{
    return input >> t.l >> t.r >> t.w;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<Tour>& t, unsigned x)
{
    const size_t n = t.size();

    std::vector<std::pair<unsigned, int>> events;
    for (int i = 1; i <= n; ++i) {
        events.emplace_back(t[i-1].l, i);
        events.emplace_back(t[i-1].r + 1, -i);
    }

    std::sort(events.begin(), events.end());

    unsigned w = oo;
    {
        std::map<unsigned, unsigned> c;
        for (const std::pair<unsigned, int>& e : events) {
            const size_t i = std::abs(e.second) - 1;

            if (e.second > 0) {
                const auto it = c.find(x - (t[i].r - t[i].l + 1));
                if (it != c.end())
                    w = std::min(w, t[i].w + it->second);
            } else {
                const auto s = c.emplace(t[i].r - t[i].l + 1, t[i].w);
                if (!s.second)
                    s.first->second = std::min(s.first->second, t[i].w);
            }
        }
    }

    w != oo ? answer(w) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<Tour> t(n);
    std::cin >> t;

    solve(t, x);

    return 0;
}
