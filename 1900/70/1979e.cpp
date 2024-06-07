#include <iostream>
#include <set>
#include <vector>

constexpr size_t B = 400000;

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

struct Point {
    int x;
    int y;
};

template <typename F>
bool check(const std::vector<Point>& p, unsigned d, F&& f)
{
    static std::vector<std::set<std::pair<int, size_t>>> s(1 + B);

    const size_t n = p.size();

    for (size_t i = 0; i < n; ++i)
        s[f(i)].emplace(p[i].x, i);

    const auto clear = [&] {
        for (size_t i = 0; i < n; ++i)
            s[f(i)].erase(std::make_pair(p[i].x, i));
    };

    for (size_t i = 0; i < n; ++i) {
        const size_t j = f(i);

        const auto it = s[j].lower_bound({ p[i].x + d / 2, 0 });
        if (it == s[j].end() || it->first != p[i].x + d / 2)
            continue;

        for (const int q : { +d, -d }) {
            if (j + q > B)
                continue;

            const auto jt = s[j+q].lower_bound({ p[i].x + q / 2, 0 });
            if (jt != s[j+q].end() && jt->first <= it->first + q / 2) {
                answer(1 + i, 1 + it->second, 1 + jt->second);
                clear();
                return true;
            }
        }
    }
    clear();
    return false;
}

void solve(const std::vector<Point>& p, unsigned d)
{
    if (check(p, d, [&](size_t i) { return p[i].x + p[i].y + 100000; }))
        return;

    if (check(p, d, [&](size_t i) { return p[i].x - p[i].y + 100000; }))
        return;

    answer(0, 0, 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<Point> p(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> p[i].x >> p[i].y;
        p[i].x += 100000;
    }

    solve(p, d);
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
