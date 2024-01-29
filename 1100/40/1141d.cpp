#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}


void solve(const std::string& l, const std::string& r)
{
    const size_t n = l.length();

    std::vector<size_t> x[28];
    for (size_t i = 0; i < n; ++i) {
        if (l[i] == '?')
            x[26].push_back(i);
        else
            x[l[i]-'a'].push_back(i);
    }

    std::vector<std::pair<size_t, size_t>> p;
    for (size_t i = 0; i < n; ++i) {
        if (r[i] == '?') {
            x[27].push_back(i);
            continue;
        }

        size_t c = r[i] - 'a';
        if (x[c].empty())
            c = 26;

        if (!x[c].empty()) {
            p.emplace_back(x[c].back(), i);
            x[c].pop_back();
        }
    }

    for (size_t i = 0; i < 27; ++i) {
        while (!x[i].empty() && !x[27].empty()) {
            p.emplace_back(x[i].back(), x[27].back());
            x[i].pop_back();
            x[27].pop_back();
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}
