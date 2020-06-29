#include <iostream>
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

void solve(std::vector<unsigned>& v)
{
    std::vector<size_t> bf(20);
    for (unsigned a : v) {
        for (size_t i = 0; i < 20; ++i) {
            if (a & (1 << i))
                ++bf[i];
        }
    }

    integer sum = 0;
    for (unsigned a : v) {
        unsigned x = 0;
        for (size_t i = 0; i < 20; ++i) {
            if (bf[i] > 0) {
                x += 1 << i;
                --bf[i];
            }
        }
        sum += 1ull * x * x;
    }

    answer(sum);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}

