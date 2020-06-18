#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b)
{
    size_t count = 0;
    while (a <= b) {
        a *= 3, b *= 2;
        ++count;
    }

    answer(count);
}

int main()
{
    size_t a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

