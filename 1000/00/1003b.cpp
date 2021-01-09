#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned x)
{
    std::string s;
    for (unsigned k = 0; k < x; k += 2) {
        s += "01";
        --a, --b;
    }

    if (x % 2 == 1)
        return answer(std::string(a, '0') + s + std::string(b, '1'));

    if (a > 0)
        return answer(std::string(a-1, '0') + s + std::string(b, '1') + '0');

    answer(std::string(b, '1') + s);
}

int main()
{
    unsigned a, b, x;
    std::cin >> a >> b >> x;

    solve(a, b, x);

    return 0;
}

