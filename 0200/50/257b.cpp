#include <iostream>

void answer(const std::pair<unsigned, unsigned>& v)
{
    std::cout << v.first << ' ' << v.second << '\n';
}

void solve(unsigned n, unsigned m)
{
    const auto simulate = [](unsigned n, unsigned m, char x) {
        std::pair<unsigned, unsigned> k = { 0, 0 };
        while (n + m > 0) {
            if (n == 0) {
                k.first += (x == 'B');
                k.second += (x != 'B');
                x = 'B';
            }
            if (m == 0) {
                k.first += (x == 'R');
                k.second += (x != 'R');
                x = 'R';
            }
            if (n != 0 && m != 0) {
                if ((k.first + k.second) % 2 == 0) {
                    ++k.first;
                } else {
                    ++k.second;
                    x = 'R' + 'B' - x;
                }
            }

            if (x == 'R')
                --n;
            else
                --m;
        }
        --k.first;
        return k;
    };

    answer(std::max(simulate(n, m, 'R'), simulate(n, m, 'B')));
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

