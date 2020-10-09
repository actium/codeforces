#include <iostream>
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

void solve(const std::vector<unsigned>& a)
{
    unsigned x1 = 1, x2 = 1000000;
    for (const unsigned x : a) {
        if (x <= 500000)
            x1 = std::max(x1, x);
        else
            x2 = std::min(x2, x);
    }

    answer(std::max(x1 - 1, 1000000 - x2));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

