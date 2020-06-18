#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    std::string s;
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0)
            s += "I hate that ";
        else
            s += "I love that ";
    }

    answer(s.substr(0, s.length() - 5) + "it");
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

