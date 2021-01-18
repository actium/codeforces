#include <iostream>
#include <map>
#include <vector>

void solve(const std::map<unsigned, unsigned>& b, const std::map<unsigned, unsigned>& s, size_t h)
{
    std::vector<std::pair<unsigned, unsigned>> p;
    for (auto it = s.begin(); it != s.end() && p.size() < h; ++it)
        p.push_back(*it);

    while (!p.empty()) {
        std::cout << 'S' << ' ' << p.back().first << ' ' << p.back().second << '\n';
        p.pop_back();
    }

    for (auto it = b.rbegin(); it != b.rend() && h > 0; ++it, --h)
        std::cout << 'B' << ' ' << it->first << ' ' << it->second << '\n';
}

int main()
{
    size_t n, h;
    std::cin >> n >> h;

    std::map<unsigned, unsigned> b, s;
    for (size_t i = 0; i < n; ++i) {
        char t;
        std::cin >> t;

        unsigned p, q;
        std::cin >> p >> q;

        if (t == 'B')
            b[p] += q;
        else
            s[p] += q;
    }

    solve(b, s, h);

    return 0;
}

