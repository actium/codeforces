#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& c, unsigned p)
{
    integer k = 0, a = 0;
    for (auto it = c.rbegin(); it != c.rend(); ++it) {
        k = k * 2 + (*it == "halfplus");
        a += k * p / 2;
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned p;
    std::cin >> p;

    std::vector<std::string> c(n);
    std::cin >> c;

    solve(c, p);

    return 0;
}

