#include <iostream>
#include <set>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& r)
{
    using point_t = std::pair<int, int>;

    unsigned t = 0;

    std::set<std::pair<point_t, char>> s;

    std::pair<int, int> p = { 0, 0 };
    for (const char c : r) {
        t += 1;
        if (s.count({ p, c }) == 0)
            t += 4;

        s.emplace(p, c);
        if (c == 'N') {
            ++p.second;
            s.emplace(p, 'S');
        }
        if (c == 'E') {
            ++p.first;
            s.emplace(p, 'W');
        }
        if (c == 'S') {
            --p.second;
            s.emplace(p, 'N');
        }
        if (c == 'W') {
            --p.first;
            s.emplace(p, 'E');
        }
    }

    answer(t);
}

void test_case()
{
    std::string r;
    std::cin >> r;

    solve(r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
