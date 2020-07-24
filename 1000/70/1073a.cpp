#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            return answer(s.substr(i-1, 2));
    }

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

