#include <iostream>
#include <string>

constexpr const char* tuc = "A      HI   M O    TUVWXY ";
constexpr const char* tlc = " d b          oqp    vwx  ";

void answer(bool v)
{
    constexpr const char* s[2] = { "NIE", "TAK" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        if (isupper(s[i]) && tuc[s[i]-'A'] != s[n-1-i])
            return answer(false);

        if (islower(s[i]) && tlc[s[i]-'a'] != s[n-1-i])
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
