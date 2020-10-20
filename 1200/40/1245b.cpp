#include <iostream>
#include <string>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::string& v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b, unsigned c)
{
    unsigned f[256] = {};
    for (const char x : s)
        ++f[x];

    std::string q[256];

    q['R'].append(std::min(f['R'], b), 'P');
    q['P'].append(std::min(f['P'], c), 'S');
    q['S'].append(std::min(f['S'], a), 'R');

    q['*'].append(b - std::min(f['R'], b), 'P');
    q['*'].append(c - std::min(f['P'], c), 'S');
    q['*'].append(a - std::min(f['S'], a), 'R');

    std::string t;
    unsigned k = 0;
    for (const char x : s) {
        std::string& r = (q[x].empty() ? q['*'] : q[x]);
        t.push_back(r.back());
        k += !q[x].empty();
        r.pop_back();
    }

    2 * k < s.length() ? no_answer() : answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    std::string s;
    std::cin >> s;

    solve(s, a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

