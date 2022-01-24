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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& s)
{
    unsigned f[1+100000] = {};

    for (unsigned x : s) {
        for (unsigned i = 2; i * i <= x; ++i) {
            if (x % i == 0)
                ++f[i];

            while (x % i == 0)
                x /= i;
        }

        ++f[x];
    }

    f[1] = 1;

    answer(*std::max_element(std::cbegin(f), std::cend(f)));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
