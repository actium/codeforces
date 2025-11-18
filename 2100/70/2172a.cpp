#include <algorithm>
#include <array>
#include <iostream>

void answer(unsigned x)
{
    std::cout << "final " << x << '\n';
}

void no_answer()
{
    std::cout << "check again" << '\n';
}

void solve(std::array<unsigned, 3>& a)
{
    std::sort(a.begin(), a.end());

    if (a[2] - a[0] < 10)
        return answer(a[1]);

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<unsigned, 3> a;
    std::cin >> a[0] >> a[1] >> a[2];

    solve(a);

    return 0;
}
