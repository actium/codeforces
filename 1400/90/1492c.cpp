#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t m = t.length();

    std::vector<size_t> lp(m);
    for (size_t i = 0, x = 0; i < m; ++i) {
        lp[i] = s.find(t[i], x);
        x = lp[i] + 1;
    }

    std::vector<size_t> rp(m);
    for (size_t i = m, x = s.length(); i-- > 0; ) {
        rp[i] = s.rfind(t[i], x);
        x = rp[i] - 1;
    }

    size_t d = 0;
    for (size_t i = 1; i < m; ++i)
        d = std::max(d, rp[i] - lp[i-1]);

    answer(d);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
