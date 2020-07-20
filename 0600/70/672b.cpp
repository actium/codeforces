#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    if (n > 26)
        return answer(-1);

    unsigned k = 0;

    bool f[26] = {};
    for (const char c : s) {
        const size_t key = c - 'a';
        k += f[key];
        f[key] = true;
    }

    answer(k);
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

