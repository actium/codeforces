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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();
    if (n == 0)
        return answer(-1);

    std::sort(a.begin(), a.end());

    if (k == 0)
        return answer(a[0] > 1 ? 1 : -1);

    answer(a[k-1] != a[k] ? a[k-1] : -1);
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

