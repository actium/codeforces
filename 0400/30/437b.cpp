#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned s, unsigned n)
{
    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i)
        q[i] = i + 1;

    std::sort(q.begin(), q.end(), [](unsigned x, unsigned y) {
        return (x & -x) > (y & -y);
    });

    std::vector<unsigned> a;
    for (const unsigned x : q) {
        if ((x & -x) <= s) {
            a.push_back(x);
            s -= x & -x;
        }
    }

    s == 0 ? answer(a) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned s, n;
    std::cin >> s >> n;

    solve(s, n);

    return 0;
}
