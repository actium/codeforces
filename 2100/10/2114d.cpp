#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(unsigned lx, unsigned ly, unsigned ux, unsigned uy)
{
    return integer(ux - lx + 1) * (uy - ly + 1);
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    if (n == 1)
        return answer(1);

    std::map<unsigned, std::vector<unsigned>> xs, ys;
    for (const auto& [x, y] : p) {
        xs[y].push_back(x);
        ys[x].push_back(y);
    }

    const auto check = [&](unsigned x, unsigned y) {
        if (xs[y].size() != 1) {
            const auto it = std::find(xs[y].begin(), xs[y].end(), x);
            *it = xs[y].back();
            xs[y].pop_back();
        } else {
            xs.erase(y);
        }

        if (ys[x].size() != 1) {
            const auto it = std::find(ys[x].begin(), ys[x].end(), y);
            *it = ys[x].back();
            ys[x].pop_back();
        } else {
            ys.erase(x);
        }

        const unsigned lx = ys.begin()->first, ly = xs.begin()->first;
        const unsigned ux = ys.rbegin()->first, uy = xs.rbegin()->first;

        xs[y].push_back(x);
        ys[x].push_back(y);

        integer a = evaluate(lx, ly, ux, uy);
        if (a < n)
            a = std::min(evaluate(lx, ly, ux + 1, uy), evaluate(lx, ly, ux, uy + 1));

        return a;
    };

    integer c = evaluate(ys.begin()->first, xs.begin()->first, ys.rbegin()->first, xs.rbegin()->first);

    if (xs.begin()->second.size() == 1)
        c = std::min(c, check(xs.begin()->second[0], xs.begin()->first));

    if (xs.rbegin()->second.size() == 1)
        c = std::min(c, check(xs.rbegin()->second[0], xs.rbegin()->first));

    if (ys.begin()->second.size() == 1)
        c = std::min(c, check(ys.begin()->first, ys.begin()->second[0]));

    if (ys.rbegin()->second.size() == 1)
        c = std::min(c, check(ys.rbegin()->first, ys.rbegin()->second[0]));

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);
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
