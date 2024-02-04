#include <deque>
#include <iostream>

using integer = unsigned long long;

void answer(const std::deque<integer>& v)
{
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

void solve(integer l, integer r, unsigned k)
{
    std::deque<integer> p = { 1 };
    while (p.back() * k / k == p.back())
        p.push_back(p.back() * k);

    while (!p.empty() && p.front() < l)
        p.pop_front();

    while (!p.empty() && p.back() > r)
        p.pop_back();

    p.empty() ? no_answer() : answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer l, r;
    std::cin >> l >> r;

    unsigned k;
    std::cin >> k;

    solve(l, r, k);

    return 0;
}
