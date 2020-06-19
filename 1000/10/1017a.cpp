#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned a, b, c, d;
        std::cin >> a >> b >> c >> d;

        s[i] = a + b + c + d;
    }

    size_t place = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] > s[0])
            ++place;
    }

    answer(place);

    return 0;
}

