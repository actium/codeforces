#include <deque>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
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
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c - '0'];

    if (f[0] != f[1])
        return no_answer();

    std::vector<size_t> p;
    {
        std::deque<char> q(s.begin(), s.end());
        for (size_t d = 0; !q.empty(); ++d) {
            if (q.front() != q.back()) {
                q.pop_front();
                q.pop_back();
                continue;
            }
            if (q.front() == '0') {
                p.push_back(q.size() + d);
                q.pop_front();
                q.push_back('0');
            } else {
                p.push_back(d);
                q.push_front('1');
                q.pop_back();
            }
        }
    }
    answer(p);
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