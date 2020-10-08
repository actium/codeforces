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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end());

    unsigned k[2] = {};
    for (size_t i = 0; i < n; ++i) {
        k[0] += abs(p[i] - (2 * i + 1));
        k[1] += abs(p[i] - (2 * i + 2));
    }

    answer(std::min(k[0], k[1]));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n / 2);
    std::cin >> p;

    solve(p);

    return 0;
}

