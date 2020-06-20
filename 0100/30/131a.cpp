#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string s)
{
    const size_t n = s.length();

    const size_t caps_count = std::count_if(s.cbegin(), s.cend(), isupper);
    if (caps_count == n || caps_count == n - 1 && islower(s[0])) {
        std::transform(s.cbegin(), s.cend(), s.begin(), tolower);

        if (caps_count < n)
            s[0] = toupper(s[0]);
    }

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

