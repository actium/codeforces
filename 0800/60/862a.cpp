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

void solve(std::vector<unsigned>& a, unsigned x)
{
    std::sort(a.begin(), a.end());

    const size_t k = std::lower_bound(a.cbegin(), a.cend(), x) - a.cbegin();
    if (k < a.size() && a[k] == x)
        answer(x - k + 1);
    else
        answer(x - k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}

