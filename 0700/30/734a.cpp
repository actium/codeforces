#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t f[2] = {};
    for (const char c : s) {
        if (c == 'A')
            ++f[0];
        else
            ++f[1];
    }

    if (f[0] == f[1])
        return answer("Friendship");

    answer(f[0] < f[1] ? "Danik" : "Anton");
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

