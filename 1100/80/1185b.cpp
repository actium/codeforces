#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    for (auto si = s.cbegin(), ti = t.cbegin(); ti != t.cend(); ++ti) {
        if (*ti == *si) {
            ++si;
            continue;
        }

        if (si == s.begin() || *ti != *std::prev(si))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    s.push_back(' ');
    t.push_back(' ');

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

