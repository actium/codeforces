#include <iostream>
#include <queue>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "D", "R" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::queue<size_t> q[2];
    for (size_t i = 0; i < n; ++i) {
        q[s[i] == 'R'].push(i);
    }

    while (!q[0].empty() && !q[1].empty()) {
        if (q[0].front() < q[1].front()) {
            q[0].push(q[0].front() + n);
        } else {
            q[1].push(q[1].front() + n);
        }
        q[0].pop();
        q[1].pop();
    }

    answer(q[0].empty());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
