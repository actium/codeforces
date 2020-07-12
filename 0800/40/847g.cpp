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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& g)
{
    unsigned k = 0;
    for (size_t i = 0; i < 7; ++i) {
        unsigned c = 0;
        for (const std::string& x : g)
            c += x[i] - '0';

        k = std::max(k, c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}

