#include <iostream>
#include <set>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct State {
    std::pair<unsigned, unsigned> p;
    std::string d;
};

bool operator <(const State& lhs, const State& rhs)
{
    return lhs.d != rhs.d ? lhs.d < rhs.d : lhs.p < rhs.p;
}

void solve(unsigned n, unsigned m, std::pair<unsigned, unsigned> s, std::pair<unsigned, unsigned> t, std::string d)
{
    const auto check = [&](const State& x) {
        if (x.d == "DL" && t.first >= x.p.first && t.second <= x.p.second)
            return t.first - x.p.first == x.p.second - t.second;

        if (x.d == "DR" && t.first >= x.p.first && t.second >= x.p.second)
            return t.first - x.p.first == t.second - x.p.second;

        if (x.d == "UL" && t.first <= x.p.first && t.second <= x.p.second)
            return x.p.first - t.first == x.p.second - t.second;

        if (x.d == "UR" && t.first <= x.p.first && t.second >= x.p.second)
            return x.p.first - t.first == t.second - x.p.second;

        return false;
    };

    const auto update = [&](State& x) {
        if (x.d == "DL") {
            const unsigned dr = n - x.p.first, dc = x.p.second - 1, v = std::min(dr, dc);
            x.p.first += v;
            x.p.second -= v;
            x.d = (dr == dc ? "UR" : dr < dc ? "UL" : "DR");
            return;
        }
        if (x.d == "DR") {
            const unsigned dr = n - x.p.first, dc = m - x.p.second, v = std::min(dr, dc);
            x.p.first += v;
            x.p.second += v;
            x.d = (dr == dc ? "UL" : dr < dc ? "UR" : "DL");
            return;
        }
        if (x.d == "UL") {
            const unsigned dr = x.p.first - 1, dc = x.p.second - 1, v = std::min(dr, dc);
            x.p.first -= v;
            x.p.second -= v;
            x.d = (dr == dc ? "DR" : dr < dc ? "DL" : "UR");
            return;
        }
        if (x.d == "UR") {
            const unsigned dr = x.p.first - 1, dc = m - x.p.second, v = std::min(dr, dc);
            x.p.first -= v;
            x.p.second += v;
            x.d = (dr == dc ? "DL" : dr < dc ? "DR" : "UL");
            return;
        }
    };

    unsigned k = 0;
    {
        std::set<State> v;
        for (State x = { s, d }; !check(x); ++k) {
            if (!v.insert(x).second)
                return no_answer();

            update(x);
        }
    }
    answer(k);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::pair<unsigned, unsigned> s, t;
    std::cin >> s >> t;

    std::string d;
    std::cin >> d;

    solve(n, m, s, t, d);
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
