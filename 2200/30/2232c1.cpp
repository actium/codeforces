#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& u, size_t x, size_t s)
{
    std::vector<std::string> t;

    const auto handle = [&](char c) {
        if (c != 'I') {
            for (std::string& q : t) {
                if (c == 'E' && q.size() > 1) {
                    const auto p = q.find('A', 1);
                    if (p != std::string::npos)
                        std::swap(q[p], c);
                }
                if (q.size() < s) {
                    q.push_back(c);
                    return;
                }
            }
        }
        if (c != 'E')
            t.emplace_back(1, c);
    };

    for (const char c : u)
        handle(c);

    t.resize(x);

    unsigned k = 0;
    for (const auto& e : t)
        k += e.size();

    answer(k);
}

void test_case()
{
    size_t n, x, s;
    std::cin >> n >> x >> s;

    std::string u;
    std::cin >> u;

    solve(u, x, s);
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
