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

void solve(const std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    if (k == 2)
        return answer(std::max(a[0], a[n-1]));

    int x = a[0];
    for (size_t i = 1; i < n; ++i) {
        if (k == 1)
            x = std::min(x, a[i]);
        else
            x = std::max(x, a[i]);
    }

    answer(x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

