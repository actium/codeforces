#include <iostream>

void solve(unsigned n)
{
    constexpr const char* t[8] = { "walk", "no", "no", "no", "yes", "yes", "backwards", "7" };
    std::cout << t[n-1] << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
