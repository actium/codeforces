#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(std::vector<unsigned>& a, integer k)
{
    const size_t n = a.size();

    if (k > n)
        k = n;

    size_t i = 0;
    for (unsigned c = 0; c < k; ++c) {
        const size_t j = (i + 1) % n;
        if (a[i] > a[j])
            std::swap(a[i], a[j]);
        else
            c = 0;

        i = j;
    }

    answer(a[i]);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

