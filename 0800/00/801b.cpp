#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& x, const std::string& y)
{
    const size_t n = x.length();

    for (size_t i = 0; i < n; ++i) {
        if (x[i] < y[i])
            return answer(-1);
    }

    answer(y);
}

int main()
{
    std::string x;
    std::cin >> x;

    std::string y;
    std::cin >> y;

    solve(x, y);

    return 0;
}

