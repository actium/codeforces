#include <iostream>
#include <string>

std::string reversed(const std::string& s)
{
    return std::string(s.rbegin(), s.rend());
}

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(std::string s)
{
    size_t p[26] = {}, x = 0;
    while (p[s[x]-'A'] == 0) {
        p[s[x]-'A'] = x + 1;
        ++x;
    }

    const std::string q[2] = {
        s.substr(p[s[x]-'A'], x - p[s[x]-'A']),
        s.substr(x+1) + s.substr(0, p[s[x]-'A']),
    };

    const size_t n = q[0].length(), m = q[1].length();

    const std::string t[2] = {
        reversed(q[1].substr(0, m / 2)) + q[0].substr(0, (n + 1) / 2),
        q[1].substr(m / 2) + reversed(q[0].substr((n + 1) / 2)),
    };

    size_t r = 0, c = 0;
    while (t[r][c] != s[0]) {
        if (++c == 13) {
            ++r;
            c = 0;
        }
    }

    const auto search = [&](char x) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0 || r + dr > 1 || c + dc > 12)
                    continue;

                if (t[r+dr][c+dc] == x)
                    return std::make_pair(dr, dc);
            }
        }
        return std::make_pair(0, 0);
    };

    for (size_t i = 1; i < 27; ++i) {
        const std::pair<int, int> d = search(s[i]);
        if (d.first == 0 && d.second == 0)
            return no_answer();

        r += d.first;
        c += d.second;
    }

    answer(t[0], t[1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
