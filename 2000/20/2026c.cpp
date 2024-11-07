#include <deque>
#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::deque<unsigned> q[2];
    for (size_t i = 0; i < n; ++i)
        q[s[i]-'0'].push_back(i + 1);

    integer v = 0;
    while (!q[1].empty()) {
        const unsigned x = q[1].back();
        q[1].pop_back();

        integer t = 0;
        while (!q[0].empty() && (q[1].empty() || q[0].back() > q[1].back())) {
            t += q[0].back();
            q[0].pop_back();
        }

        if (t == 0 && !q[0].empty()) {
            t += q[0].back();
            q[0].pop_back();
        }

        if (t == 0 && !q[1].empty()) {
            t += q[1].front();
            q[1].pop_front();
        }

        v += (t != 0 ? t : x);
    }

    answer(v);
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
