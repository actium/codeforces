#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    unsigned fa[26] = {};
    for (const char c : a)
        ++fa[c - 'a'];

    unsigned fb[26] = {};
    for (const char c : b)
        ++fb[c - 'a'];

    unsigned k = 0;
    for (size_t i = 0; i < 26; ++i) {
        if (fb[i] == 0)
            continue;

        if (fa[i] == 0)
            return no_answer();

        k += std::min(fa[i], fb[i]);
    }

    answer(k);
}

int main()
{
    std::string a;
    std::cin >> a;

    std::string b;
    std::cin >> b;

    solve(a, b);

    return 0;
}

