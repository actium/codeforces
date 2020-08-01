#include <iostream>
#include <string>

bool test(const std::string& s, const std::string& p)
{
    const size_t n = s.length();
    if (n != p.length())
        return false;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] != p[i] && s[i] != '.')
            return false;
    }
    return true;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const std::string pokemons[8] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };

    for (const std::string& p : pokemons) {
        if (test(s, p))
            return answer(p);
    }
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

