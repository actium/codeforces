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
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> y;
    for (size_t i = 0, j = 1; i < n; ++i) {
        if (a[i] == j) {
            y.push_back(2001 + i);
            ++j;
        }
    }

    answer(y);
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

