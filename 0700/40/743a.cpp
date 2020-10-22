#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b)
{
    answer(s[a-1] ^ s[b-1]);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);

    return 0;
}

