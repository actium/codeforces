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

void solve(const std::vector<unsigned>& d, unsigned k)
{
    unsigned c = 0;

    std::vector<unsigned> f(k);
    for (const unsigned x : d) {
        const unsigned y = k - x % k;
        if (f[y % k] == 0) {
            ++f[x % k];
        }  else {
            --f[y % k];
            c += 2;
        }
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d, k);

    return 0;
}

