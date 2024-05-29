#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(integer n, integer k)
{
    if (k > 50)
        return answer(false);

    for (unsigned i = 2; i <= k; ++i) {
        if ((n + 1) % i != 0)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
