#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned c)
{
    std::vector<unsigned> d;
    for ( ; a + c != 0; a /= 3, c /= 3) {
        const unsigned x = a % 3;
        const unsigned y = c % 3;
        d.push_back((3 + y - x) % 3);
    }

    unsigned b = 0;
    while (!d.empty()) {
        b = b * 3 + d.back();
        d.pop_back();
    }

    answer(b);
}

int main()
{
    unsigned a, c;
    std::cin >> a >> c;

    solve(a, c);

    return 0;
}

