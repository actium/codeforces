#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    size_t x[3] = {};
    for (size_t i = 0; i < n; ++i) {
        if (p[i] < 3)
            x[p[i]-1] = i;

        if (p[i] == n)
            x[2] = i;
    }

    if (x[2] < std::min(x[0], x[1]))
        return answer(std::min(x[0], x[1]), x[2]);

    if (x[2] > std::max(x[0], x[1]))
        return answer(std::max(x[0], x[1]), x[2]);

    answer(0, 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
