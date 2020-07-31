#include <iostream>
#include <vector>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned a, unsigned b)
{
    std::vector<unsigned> x(1, b);
    while (b > a) {
        if (b % 2 != 0 && b % 10 != 1)
            return no_answer();

        if (b % 2 == 0)
            b /= 2;
        else
            b = (b - 1) / 10;

        x.push_back(b);
    }

    if (b != a)
        return no_answer();

    answer(x);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

