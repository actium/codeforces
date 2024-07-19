#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer u, integer v)
{
    if (v < u)
        return no_answer();

    const integer d = v - u;
    if (d % 2 == 1)
        return no_answer();

    std::vector<integer> a;
    if (v != 0) {
        const integer b = d / 2;
        if ((u & b) == 0) {
            a.push_back(u | b);
        } else {
            a.push_back(u);
            a.push_back(b);
        }

        if (b != 0)
            a.push_back(b);
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer u, v;
    std::cin >> u >> v;

    solve(u, v);

    return 0;
}
