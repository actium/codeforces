#include <iostream>
#include <set>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::string time_to_string(unsigned t)
{
    const unsigned h = t / 60, m = t % 60;

    char s[16];
    snprintf(s, sizeof(s), "%02u:%02u", h, m);
    return s;
}

void solve(const std::string& s, unsigned x)
{
    unsigned t = std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3));

    std::set<unsigned> v;
    while (v.count(t) == 0) {
        v.insert(t);
        t = (t + x) % (24 * 60);
    }

    unsigned k = 0;
    for (const unsigned t : v) {
        const std::string s = time_to_string(t);
        if (s == std::string(s.rbegin(), s.rend()))
            ++k;
    }

    answer(k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    unsigned x;
    std::cin >> x;

    solve(s, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
