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
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        if (a[i] >= 0)
            a[i] = ~a[i];
    }

    if (n % 2 == 1) {
        size_t x = 0;
        for (size_t i = 1; i < n; ++i) {
            if (a[i] < a[x])
                x = i;
        }

        a[x] = ~a[x];
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
