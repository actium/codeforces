#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(const std::string& s)
{
    std::vector<std::pair<size_t, size_t>> p;

    size_t hr = 0, vr = 0;
    for (const char c : s) {
        if (c == '0') {
            p.emplace_back(vr, 2);
            vr = (vr + 2) % 4;
        } else {
            p.emplace_back(hr, 0);
            hr = (hr + 1) % 4;
        }
    }

    answer(p);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
