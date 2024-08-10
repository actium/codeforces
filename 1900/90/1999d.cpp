#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::string& s, const std::string& t)
{
    auto ti = t.begin();
    for (auto si = s.begin(); si != s.end() && ti != t.end(); ++si) {
        if (*si == '?')
            *si = *ti;

        if (*si == *ti)
            ++ti;
    }

    if (ti != t.end())
        return no_answer();

    for (size_t x = s.find('?'); x != std::string::npos; x = s.find('?', x+1))
        s[x] = 'a';

    answer(s);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
