#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string x : v)
        std::cout << x << '\n';
}

void solve(unsigned h1, unsigned a1, unsigned c1, unsigned h2, unsigned a2)
{
    std::vector<std::string> a;
    while (h2 > 0) {
        if (a1 >= h2 || h1 > a2) {
            a.push_back("STRIKE");
            h2 -= std::min(h2, a1);
        } else {
            a.push_back("HEAL");
            h1 += c1;
        }
        h1 -= a2;
    }

    answer(a);
}

int main()
{
    unsigned h1, a1, c1;
    std::cin >> h1 >> a1 >> c1;

    unsigned h2, a2;
    std::cin >> h2 >> a2;

    solve(h1, a1, c1, h2, a2);

    return 0;
}

