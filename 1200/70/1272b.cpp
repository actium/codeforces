#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v.length() << '\n';
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned f[256] = {};
    for (const char c : s)
        ++f[c];

    f['U'] = f['D'] = std::min(f['U'], f['D']);
    f['R'] = f['L'] = std::min(f['R'], f['L']);

    if (f['U'] == 0 && f['R'] == 0)
        return answer("");

    if (f['U'] == 0)
        return answer("RL");

    if (f['R'] == 0)
        return answer("UD");

    std::string t;
    t.append(f['U'], 'U');
    t.append(f['R'], 'R');
    t.append(f['D'], 'D');
    t.append(f['L'], 'L');

    answer(t);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

