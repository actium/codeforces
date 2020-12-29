#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& p1, const std::string& p2)
{
    const unsigned x1 = p1.front() - 'a', y1 = p1.back() - '1';
    const unsigned x2 = p2.front() - 'a', y2 = p2.back() - '1';

    const auto check = [=](unsigned x, unsigned y) {
        const std::pair<unsigned, unsigned> p[] = {
            { x+1, y-2 }, { x+2, y-1 }, { x+2, y+1 }, { x+1, y+2 },
            { x-1, y+2 }, { x-2, y+1 }, { x-2, y-1 }, { x-1, y-2 },
        };

        for (const auto& q : p) {
            if (q.first == x1 && q.second == y1)
                return false;

            if (q.first == x2 && q.second == y2)
                return false;
        }
        return (x != x1 && y != y1) && (x != x2 || y != y2);
    };

    unsigned k = 0;
    for (size_t x = 0; x < 8; ++x) {
        for (size_t y = 0; y < 8; ++y)
            k += check(x, y);
    }

    answer(k);
}

int main()
{
    std::string p1, p2;
    std::cin >> p1 >> p2;

    solve(p1, p2);

    return 0;
}

