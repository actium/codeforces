#include <iostream>
#include <string>

void no_answer()
{
    std::cout << "No solution" << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned d)
{
    if (d == 0 && k > 1)
        return no_answer();

    std::string n(k, '0');
    n.front() = '0' + d;

    answer(n);
}

int main()
{
    unsigned k, d;
    std::cin >> k >> d;

    solve(k, d);

    return 0;
}

