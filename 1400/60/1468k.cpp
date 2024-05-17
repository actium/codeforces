#include <iostream>
#include <string>
#include <vector>

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << 0 << ' ' << 0 << '\n';
}

std::pair<int, int> step(const std::pair<int, int>& p, char c, const std::pair<int, int>& x)
{
    std::pair<int, int> q = p;
    switch (c) {
        case 'U': ++q.second; break;
        case 'R': ++q.first; break;
        case 'D': --q.second; break;
        case 'L': --q.first; break;
    }
    return q != x ? q : p;
}

void solve(const std::string& p)
{
    const size_t n = p.length();

    const auto check = [&](const std::pair<int, int>& x) {
        std::pair<int, int> q = { 0, 0 };
        for (const char c : p)
            q = step(q, c, x);

        return q.first == 0 && q.second == 0;
    };

    std::pair<int, int> q = { 0, 0 };
    for (size_t i = 0; i < n; ++i) {
        const std::pair<int, int> x = step(q, p[i], q);
        if (check(x))
            return answer(x.first, x.second);

        q = x;
    }

    no_answer();
}

void test_case()
{
    std::string p;
    std::cin >> p;

    solve(p);
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
