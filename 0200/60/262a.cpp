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

size_t count_lucky_digits(unsigned n)
{
    size_t count = 0;
    while (n != 0) {
        const unsigned digit = n % 10;
        if (digit == 4 || digit == 7)
            ++count;

        n /= 10;
    }
    return count;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    answer(std::count_if(a.cbegin(), a.cend(), [k](unsigned x) { return count_lucky_digits(x) <= k; }));
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

