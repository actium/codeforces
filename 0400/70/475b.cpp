#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& h, const std::string& v)
{
    if (h.front() == '<' && v.front() == 'v' && h.back() == '>' && v.back() == '^')
        return answer(true);

    if (h.front() == '>' && v.front() == '^' && h.back() == '<' && v.back() == 'v')
        return answer(true);

    answer(false);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string h, v;
    std::cin >> h >> v;

    solve(h, v);

    return 0;
}
