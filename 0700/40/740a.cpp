#include <algorithm>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c)
{
    switch (n % 4) {
        case 1:
            return answer(std::min({ 3 * a, a + b, c }));

        case 2:
            return answer(std::min({ 2 * a, b, 2 * c }));

        case 3:
            return answer(std::min({ a, b + c, 3 * c }));
    }

    answer(0);
}

int main()
{
    unsigned n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);

    return 0;
}

