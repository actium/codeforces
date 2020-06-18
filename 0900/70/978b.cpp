#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t x_count = 0, r_count = 0;
    for (const char c : s) {
        if (c == 'x')
            ++x_count;
        else
            x_count = 0;

        if (x_count >= 3)
            ++r_count;
    }

    answer(r_count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

