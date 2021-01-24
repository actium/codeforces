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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const auto check = [&a](size_t h) {
        if (h % 2 == 1)
            return false;

        for (size_t i = 0; i < h / 2; ++i) {
            if (a[i] != a[h-1-i])
                return false;
        }
        return true;
    };

    size_t h = a.size();
    while (check(h))
        h /= 2;

    answer(h);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}

