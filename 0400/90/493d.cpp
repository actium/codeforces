#include <iostream>

void solve(unsigned n)
{
    if (n % 2 == 0) {
        std::cout << "white" << '\n';
        std::cout << 1 << ' ' << 2 << '\n';
    } else {
        std::cout << "black" << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
