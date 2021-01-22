#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<std::vector<std::string>>& x)
{
    std::set<std::string> u;

    std::queue<std::string> q;
    for (q.push("a"); !q.empty(); q.pop()) {
        const std::string s = q.front();

        if (s.length() == n) {
            u.insert(s);
            continue;
        }

        for (const std::string& p : x[s.front() - 'a'])
            q.push(p + s.substr(1));
    }

    answer(u.size());
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<std::vector<std::string>> x(6);
    for (size_t i = 0; i < q; ++i) {
        std::string a, b;
        std::cin >> a >> b;

        if (a.front() <= 'f' && a.back() <= 'f')
            x[b.front() - 'a'].push_back(a);
    }

    solve(n, x);

    return 0;
}

