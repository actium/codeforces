#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size() + 1;

    std::vector<unsigned> z;
    for (size_t x = n; x > 1; x = p[x-2])
        z.push_back(x);

    z.push_back(1);

    std::reverse(z.begin(), z.end());

    answer(z);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    solve(p);

    return 0;
}

