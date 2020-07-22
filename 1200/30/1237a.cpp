#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    for (const int x : v)
        std::cout << x << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    int c = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] % 2 != 0) {
            a[i] += c;
            c = a[i] % 2;
        }
        a[i] /= 2;
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

