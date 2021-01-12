#include <iostream>
#include <string>

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::string& s)
{
    const size_t x = s.find('R');
    if (x != std::string::npos)
        return answer(x, s.rfind('R') + 1);

    answer(s.rfind('L'), s.find('L') - 1);
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

