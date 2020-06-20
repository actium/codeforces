#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    size_t c[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (a[i] < 0)
            ++c[0];

        if (a[i] > 0)
            ++c[1];
    }

    if (c[1] >= (n + 1) / 2)
        return answer(1);

    if (c[0] >= (n + 1) / 2)
        return answer(-1);

    answer(0);
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

