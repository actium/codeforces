#include <iostream>
#include <string>

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    std::string s;
    for (size_t i = 0; i < n; ++i)
        s += std::to_string(i+1);

    answer(s[n-1]);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

