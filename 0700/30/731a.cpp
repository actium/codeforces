#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t count = 0;

    char state = 'a';
    for (const char c : s) {
        const size_t delta = abs(c - state) % 26;
        count += std::min(delta, 26 - delta);
        state = c;
    }

    answer(count);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

