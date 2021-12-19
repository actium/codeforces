#include <iostream>
#include <string>

void answer(int x)
{
    constexpr const char c[3] = { '<', '=', '>' };
    std::cout << c[x+1] << '\n';
}

void solve(unsigned x1, unsigned p1, unsigned x2, unsigned p2)
{
    const unsigned p = std::min(p1, p2);
    p1 -= p, p2 -= p;

    std::string y1 = std::to_string(x1), y2 = std::to_string(x2);
    if (y1.length() + p1 != y2.length() + p2)
        return answer(y1.length() + p1 > y2.length() + p2 ? 1 : -1);

    y1.resize(y1.length() + p1, '0'), y2.resize(y2.length() + p2, '0');
    if (y1 != y2)
        return answer(y1 > y2 ? 1 : -1);

    answer(0);
}

void test_case()
{
    unsigned x1, p1;
    std::cin >> x1 >> p1;

    unsigned x2, p2;
    std::cin >> x2 >> p2;

    solve(x1, p1, x2, p2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
