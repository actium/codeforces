#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<int>& x)
{
    const size_t n = x.size();

    for (size_t i = 0; i < n; ++i) {
        const int min = std::min(abs(x[i] - x[(i+n-1)%n]), abs(x[i] - x[(i+1)%n]));
        const int max = std::max(abs(x[i] - x.front()), abs(x[i] - x.back()));
        answer(min, max);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x);

    return 0;
}

