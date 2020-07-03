#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t;
    for (int i = n - 2; i >= 0; i -= 2) {
        t.push_back(s[i]);
    }
    for (int i = 1 - n % 2; i < n; i += 2) {
        t.push_back(s[i]);
    }

    answer(t);
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

