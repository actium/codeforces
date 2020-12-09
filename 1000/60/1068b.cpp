#include <iostream>
#include <set>

using integer = unsigned long long;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(integer b)
{
    std::set<integer> f;
    for (integer x = 1; x * x <= b; ++x) {
        if (b % x == 0) {
            f.insert(x);
            f.insert(b / x);
        }
    }

    answer(f.size());
}

int main()
{
    integer b;
    std::cin >> b;

    solve(b);

    return 0;
}

