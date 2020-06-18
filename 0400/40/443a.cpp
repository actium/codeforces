#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t count = 0;

    bool used[26] = {};
    for (const char c : s) {
        if (!isalpha(c))
            continue;

        if (!used[c - 'a'])
            ++count;

        used[c - 'a'] = true;
    }

    answer(count);
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    solve(s);

    return 0;
}

