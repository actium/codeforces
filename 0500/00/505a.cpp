#include <iostream>
#include <string>

bool check(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i])
            return false;
    }
    return true;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i]) {
            const std::string x = s.substr(0, i) + s[n-1-i] + s.substr(i);
            if (check(x))
                return answer(x);

            const std::string y = s.substr(0, n-i) + s[i] + s.substr(n-i);
            if (check(y))
                return answer(y);

            return answer("NA");
        }
    }

    answer(s.substr(0, n/2) + s[n/2] + s.substr(n/2));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

