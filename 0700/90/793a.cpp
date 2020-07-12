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

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const unsigned m = *std::min_element(a.cbegin(), a.cend());

    unsigned long long c = 0;
    for (const unsigned x : a) {
        if ((x - m) % k != 0)
            return answer(-1);

        c += (x - m) / k;
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

