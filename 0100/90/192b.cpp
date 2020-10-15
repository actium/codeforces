#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();
    if (n == 1)
        return answer(a[0]);

    a[1] = std::min(a[0], a[1]);
    for (size_t i = 2; i < n; ++i)
        a[i] = std::min(a[i], std::max(a[i-1], a[i-2]));

    answer(a.back());
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

