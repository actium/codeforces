#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    if (n < 7)
        return answer(false);

    size_t counts[2] = {};
    for (size_t i = 0; i < 7; ++i) {
        const char key = s[i];
        ++counts[key - '0'];
    }

    for (size_t left = 0, right = 7; right < n && counts[0] != 7 && counts[1] != 7; ++left, ++right) {
        --counts[s[left] - '0'];
        ++counts[s[right] - '0'];
    }

    answer(counts[0] == 7 || counts[1] == 7);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

