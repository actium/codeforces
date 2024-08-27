#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t p[26] = {};
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'] = i;

    p[25] = n-1;     // sentinel

    std::string t, u;
    for (size_t c = 0, i = 0; c < 26; ) {
        while (!t.empty() && t.back() <= 'a' + c) {
            u.push_back(t.back());
            t.pop_back();
        }

        if (i <= p[c])
            t.push_back(s[i++]);
        else
            ++c;
    }

    u.append(t.rbegin(), t.rend());

    answer(u);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
