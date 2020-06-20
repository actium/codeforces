#include <algorithm>
#include <iostream>
#include <vector>

struct Entry {
    int power;
    int bonus;
};

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t s, std::vector<Entry>& xy)
{
    const size_t n = xy.size();

    std::sort(xy.begin(), xy.end(), [](const Entry& a, const Entry& b) { return a.power < b.power; });

    size_t count = 0;
    for (size_t i = 0; i < n && s > xy[i].power; ++i) {
        ++count;
        s += xy[i].bonus;
    }

    answer(count == n);
}

int main()
{
    size_t s, n;
    std::cin >> s >> n;

    std::vector<Entry> xy(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> xy[i].power >> xy[i].bonus;

    solve(s, xy);

    return 0;
}

