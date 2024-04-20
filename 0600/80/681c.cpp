#include <iostream>
#include <queue>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    std::vector<std::string> t;
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for (const std::string& r : s) {
            if (r[0] == 'i') {
                const int x = std::stoi(r.substr(7));
                q.push(x);
            }
            if (r[0] == 'g') {
                const int x = std::stoi(r.substr(7));
                while (!q.empty() && q.top() < x) {
                    q.pop();
                    t.push_back("removeMin");
                }
                if (q.empty() || q.top() != x) {
                    q.push(x);
                    t.push_back("insert" + r.substr(6));
                }
            }
            if (r[0] == 'r') {
                if (q.empty()) {
                    q.push(1);
                    t.push_back("insert 1");
                }
                q.pop();
            }
            t.push_back(r);
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n >> std::ws;

    std::vector<std::string> s(n);
    for (size_t i = 0; i < n; ++i)
        std::getline(std::cin, s[i]);

    solve(s);

    return 0;
}
