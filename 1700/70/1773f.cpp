#include <iostream>
#include <vector>

using result_t = std::pair<unsigned, unsigned>;

void answer(const std::vector<result_t>& x, const std::vector<result_t>& y)
{
    std::cout << y.size() << '\n';

    for (const result_t& r : x)
        std::cout << r.first << ':' << r.second << '\n';

    for (const result_t& r : y)
        std::cout << r.first << ':' << r.second << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    std::vector<result_t> s;
    for ( ; n != 1 && a + b != 0; --n) {
        if (a == 0) {
            s.emplace_back(0, 1);
            --b;
            continue;
        }
        if (b == 0) {
            s.emplace_back(1, 0);
            --a;
            continue;
        }
        if (a >= n) {
            s.emplace_back(0, b);
            b = 0;
            continue;
        }
        if (b >= n) {
            s.emplace_back(a, 0);
            a = 0;
            continue;
        }
        if (a < b) {
            s.emplace_back(1, 0);
            --a;
        } else {
            s.emplace_back(0, 1);
            --b;
        }
    }

    std::vector<result_t> t;
    if (n == 1) {
        (a != b ? s : t).emplace_back(a, b);
    } else {
        t.resize(n, std::make_pair(0, 0));
    }

    answer(s, t);
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}
