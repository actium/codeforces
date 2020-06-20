#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a, size_t m)
{
    const size_t n = a.size();

    size_t i = 0;
    for (size_t k = 0; k < n; i = (i + 1) % n) {
        if (a[i] > 0) {
            a[i] -= m;
            k += (a[i] <= 0);
        }
    }

    answer(i == 0 ? n : i);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

