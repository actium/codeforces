#include <iostream>
#include <set>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    std::set<unsigned> s;
    for (unsigned k = 1; k * k < 2 * n; ++k) {
        const unsigned t = k * (k + 1) / 2;
        s.insert(t);

        if (s.count(n - t) == 1)
            return answer(true);
    }

    answer(false);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

