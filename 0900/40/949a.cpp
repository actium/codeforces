#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

std::ostream& operator <<(std::ostream& output, const std::vector<size_t>& v)
{
    output << v.size();
    for (const size_t x : v)
        output << ' ' << 1+x;

    return output;
}

void answer(const std::vector<std::vector<size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<size_t>& x : v)
        std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<std::vector<size_t>> t;
    {
        std::vector<size_t> p, q;
        for (size_t i = 0; i < n; ++i) {
            switch (s[i]) {
                case '0':
                    if (!q.empty()) {
                        p.push_back(q.back());
                        q.pop_back();
                    } else {
                        p.push_back(t.size());
                        t.emplace_back();
                    }
                    t[p.back()].push_back(i);
                    break;

                case '1':
                    if (!p.empty()) {
                        q.push_back(p.back());
                        p.pop_back();
                    } else {
                        return no_answer();
                    }
                    t[q.back()].push_back(i);
                    break;
            }
        }

        if (!q.empty())
            return no_answer();
    }
    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
