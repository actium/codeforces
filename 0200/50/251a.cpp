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

void solve(const std::vector<int>& x, unsigned d)
{
    const size_t n = x.size();
    if (n < 3)
        return answer(0);

    integer k = 0;
    for (size_t i = 0, j = 2; j < n; ++j) {
        while (x[j] - x[i] > d)
            ++i;

        const integer d = j - i;
        k += d * (d - 1) / 2;
    }

    answer(k);
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

