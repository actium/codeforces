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

void solve(std::vector<int>& x, unsigned d)
{
    const size_t n = x.size();

    std::sort(x.begin(), x.end());

    unsigned c = 2;
    for (size_t i = 1; i < n; ++i) {
        const unsigned dx = x[i] - x[i-1];

        if (dx > 2 * d)
            c += 2;

        if (dx == 2 * d)
            ++c;
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x, d);

    return 0;
}

