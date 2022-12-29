#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        a[i] -= i + 1;
        if (i != 0 && a[i] <= a[i-1])
            a[i] = a[i-1] + 1;
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
