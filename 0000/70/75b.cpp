#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Event {
    std::string s;
    std::string t;
    unsigned v;
};

Event parse(const std::string& s)
{
    Event e;
    {
        const size_t x = s.find(" posted on ");
        if (x != std::string::npos) {
            const size_t y = s.find("'s wall");

            e.s = s.substr(0, x);
            e.t = s.substr(x + 11, y - (x + 11));
            e.v = 15;
        }
    }
    {
        const size_t x = s.find(" commented on ");
        if (x != std::string::npos) {
            const size_t y = s.find("'s post");

            e.s = s.substr(0, x);
            e.t = s.substr(x + 14, y - (x + 14));
            e.v = 10;
        }
    }
    {
        const size_t x = s.find(" likes ");
        if (x != std::string::npos) {
            const size_t y = s.find("'s post");

            e.s = s.substr(0, x);
            e.t = s.substr(x + 7, y - (x + 7));
            e.v = 5;
        }
    }
    return e;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::string& x, const std::vector<std::string>& r)
{
    std::map<std::string, unsigned> v;
    for (const std::string& s : r) {
        const Event e = parse(s);
        if (e.s != x && e.t != x) {
            v[e.s] += 0;
            v[e.t] += 0;
        } else {
            v[e.s == x ? e.t : e.s] += e.v;
        }
    }

    std::vector<std::string> p;
    for (const auto& e : v) {
        if (e.first != x)
            p.push_back(e.first);
    }

    std::sort(p.begin(), p.end(), [&](const std::string& lhs, const std::string& rhs) {
        return v[lhs] != v[rhs] ? v[lhs] > v[rhs] : lhs < rhs;
    });

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string x;
    std::cin >> x;

    size_t n;
    std::cin >> n >> std::ws;

    std::vector<std::string> r(n);
    for (size_t i = 0; i < n; ++i)
        std::getline(std::cin, r[i]);

    solve(x, r);

    return 0;
}
