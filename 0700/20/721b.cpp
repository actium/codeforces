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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<std::string>& p, const std::string& e, unsigned k)
{
    unsigned c1 = 0, c2 = 0;
    for (const std::string& x : p) {
        c1 += (x.size() < e.size());
        c2 += (x.size() == e.size());
    }

    answer(c1 + 1 + c1 / k * 5, c1 + c2 + (c1 + c2 - 1) / k * 5);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<std::string> p(n);
    std::cin >> p;

    std::string e;
    std::cin >> e;

    solve(p, e, k);

    return 0;
}

