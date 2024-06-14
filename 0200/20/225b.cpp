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

void solve(unsigned s, unsigned k)
{
    std::vector<unsigned> v = { 0, 1 };
    while (v.back() < s) {
        unsigned t = 0;
        for (unsigned n = v.size(), i = n - std::min(n, k); i < n; ++i)
            t += v[i];

        v.push_back(t);
    }

    std::vector<unsigned> q(1);
    while (s != 0) {
        if (v.back() <= s && v.back() != q.back()) {
            q.push_back(v.back());
            s -= v.back();
        }
        v.pop_back();
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned s, k;
    std::cin >> s >> k;

    solve(s, k);

    return 0;
}
