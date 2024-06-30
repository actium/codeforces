#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << 0 << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

bool check(const std::string& t, unsigned b, unsigned ub)
{
    unsigned v = 0;
    for (const char c : t) {
        const unsigned d = (c < 'A' ? c - '0' : c - 'A' + 10);
        if (d >= b)
            return false;

        v = v * b + d;
    }
    return v <= ub;
}

void solve(const std::string& s)
{
    const size_t x = s.find(':');

    const std::string h = s.substr(0, x), m = s.substr(x + 1);

    std::vector<unsigned> v;
    for (unsigned b = 2; b <= 60; ++b) {
        if (check(h, b, 23) && check(m, b, 59))
            v.push_back(b);
    }

    if (v.empty())
        return no_answer();

    v.back() < 60 ? answer(v) : infinity();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
