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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t count = 0;
    for (size_t i = 1; i < n - 1; ++i) {
        if (a[i-1] < a[i] && a[i] > a[i+1] || a[i-1] > a[i] && a[i] < a[i+1])
            ++count;
    }

    answer(count);
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

