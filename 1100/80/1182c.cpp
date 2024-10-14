#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<std::string_view, std::string_view>>& v)
{
    std::cout << v.size() / 2 << '\n';

    for (const std::pair<std::string_view, std::string_view>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

std::string reduce(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
            t.push_back(c);
    }
    return t;
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<size_t, size_t>> p[26], q;
    for (size_t i = 0; i < n; ++i) {
        const std::string t = reduce(s[i]);
        p[t.back()-'a'].emplace_back(t.length(), i);
    }

    for (size_t i = 0; i < 26; ++i)
        std::sort(p[i].begin(), p[i].end());

    std::vector<size_t> z;
    for (size_t i = 0; i < 26; ++i) {
        for (size_t j = 0; j < p[i].size(); ) {
            if (j + 1 < p[i].size() && p[i][j+1].first == p[i][j].first) {
                z.push_back(p[i][j++].second);
                z.push_back(p[i][j++].second);
            } else {
                q.push_back(p[i][j++]);
            }
        }
    }

    std::sort(q.begin(), q.end());

    std::vector<size_t> a;
    for (size_t i = 0; i < q.size(); ) {
        if (i + 1 < q.size() && q[i+1].first == q[i].first) {
            a.push_back(q[i++].second);
            a.push_back(q[i++].second);
        } else {
            ++i;
        }
    }

    std::vector<std::pair<std::string_view, std::string_view>> v;
    while (!a.empty() && !z.empty()) {
        for (size_t i = 0; i < 2; ++i) {
            v.emplace_back(s[a.back()], s[z.back()]);
            a.pop_back();
            z.pop_back();
        }
    }
    for (size_t i = 3; i < z.size(); i += 4) {
        v.emplace_back(s[z[i-0]], s[z[i-2]]);
        v.emplace_back(s[z[i-1]], s[z[i-3]]);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
