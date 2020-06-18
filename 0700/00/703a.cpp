#include <iostream>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const size_t counts[2])
{
    if (counts[0] == counts[1])
        return answer("Friendship is magic!^^");

    answer(counts[0] > counts[1] ? "Mishka" : "Chris");
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t counts[2] = {};
    for (size_t i = 0; i < n; ++i) {
        unsigned m, c;
        std::cin >> m >> c;

        if (m != c)
            ++counts[m < c];
    }

    solve(counts);

    return 0;
}

