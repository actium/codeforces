#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';

    const char* separator = "";
    for (const unsigned v : y) {
        std::cout << separator << v;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    int b = 0;
    for (const char c : s)
        b += (c == '(' ? +1 : -1);

    if (b != 0)
        return no_answer();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::vector<unsigned> c(n);
    for (unsigned k = 1; !p.empty(); ++k) {
        std::vector<size_t> q, r = { p.front() };
        for (size_t i = 1; i < p.size(); ++i) {
            if (r.empty()) {
                if (s[p[i]] == s[p[0]])
                    r.push_back(p[i]);
                else
                    q.push_back(p[i]);
            } else {
                if (s[p[i]] != s[r.back()]) {
                    c[p[i]] = k;
                    c[r.back()] = k;
                    r.pop_back();
                } else {
                    r.push_back(p[i]);
                }
            }
        }

        const auto it = std::merge(r.begin(), r.end(), q.begin(), q.end(), p.begin());
        p.erase(it, p.end());
    }

    answer(*std::max_element(c.begin(), c.end()), c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
