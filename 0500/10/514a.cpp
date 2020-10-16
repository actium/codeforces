#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& x)
{
    const size_t n = x.length();

    for (size_t i = (x[0] == '9'); i < n; ++i) {
        if (x[i] > '4')
            x[i] = '0' + ('9' - x[i]);
    }

    answer(x);
}

int main()
{
    std::string x;
    std::cin >> x;

    solve(x);

    return 0;
}

