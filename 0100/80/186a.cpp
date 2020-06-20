#include <iostream>
#include <string>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s1, const std::string& s2)
{
    const size_t n = s1.length();
    if (s2.length() != n)
        return answer(false);

    std::vector<size_t> diffs;
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i])
            diffs.push_back(i);

        if (diffs.size() > 2)
            return answer(false);
    }

    answer(diffs.size() == 2 && s1[diffs.front()] == s2[diffs.back()] && s1[diffs.back()] == s2[diffs.front()]);
}

int main()
{
    std::string g1, g2;
    std::cin >> g1 >> g2;

    solve(g1, g2);

    return 0;
}

