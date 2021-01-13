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

void solve(std::vector<unsigned>& a)
{
    unsigned f[3] = {};
    for (unsigned q : a) {
        unsigned s = 0;
        for ( ; q != 0; q /= 10)
            s += q % 10;

        ++f[s % 3];
    }

    answer(f[0] / 2 + std::min(f[1], f[2]));
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

