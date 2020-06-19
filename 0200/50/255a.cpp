#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t f[3] = {};
    for (size_t i = 0; i < n; ++i)
        f[i % 3] += a[i];

    if (f[0] > f[1] && f[0] > f[2])
        return answer("chest");

    if (f[1] > f[2])
        return answer("biceps");

    answer("back");
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

