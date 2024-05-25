#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned k)
{
    std::string s("z");
    for (char c = 'a'; k != 0; ++c) {
        unsigned d = 1;
        while (d * (d + 1) / 2 <= k)
            ++d;

        s.append(d, c);
        k -= d * (d - 1) / 2;
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}
