#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& a)
{
    const size_t n = a.length();

    size_t i = 0;
    while (i < n && a[i] == '1')
        ++i;

    if (i == n)
        a.pop_back();
    else
        a.erase(i, 1);

    answer(a);
}

int main()
{
    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}

