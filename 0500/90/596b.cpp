#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& b)
{
    const size_t n = b.size();

    unsigned long long s = abs(b.front());
    for (size_t i = 1; i < n; ++i)
        s += abs(b[i] - b[i-1]);

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

