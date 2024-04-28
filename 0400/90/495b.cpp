#include <iostream>
#include <set>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void infinity()
{
    std::cout << "infinity" << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a < b)
        return answer(0);

    if (a > b) {
        const unsigned x = a - b;

        std::set<unsigned> s;
        for (unsigned i = 1; i * i <= x; ++i) {
            if (x % i != 0)
                continue;

            if (x / i > b)
                s.insert(x / i);

            if (i > b)
                s.insert(i);
        }
        return answer(s.size());
    }

    infinity();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
