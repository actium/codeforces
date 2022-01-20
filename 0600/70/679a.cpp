#include <iostream>
#include <string>

bool query(unsigned x)
{
    std::cout << x << std::endl;

    std::string y;
    std::cin >> y;
    return y == "yes";
}

void answer(bool v)
{
    constexpr const char* s[2] = { "composite", "prime" };
    std::cout << s[v] << std::endl;
}

void solve()
{
    constexpr unsigned p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

    unsigned c = 0;
    for (const unsigned x : p) {
        if (!query(x))
            continue;

        if (c != 0)
            return answer(false);

        c = x;

        if (x * x <= 100 && query(x * x))
            return answer(false);
    }

    answer(true);
}

int main()
{
    solve();

    return 0;
}
