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

void solve(const std::vector<size_t>& a, size_t t)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        if (86400 - a[i] >= t)
            return answer(i + 1);

        t -= 86400 - a[i];
    }

    answer(n);
}

int main()
{
    size_t n, t;
    std::cin >> n >> t;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, t);

    return 0;
}

