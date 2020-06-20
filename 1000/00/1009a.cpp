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

void solve(const std::vector<unsigned>& c, const std::vector<unsigned>& a)
{
    const size_t n = c.size();
    const size_t m = a.size();

    size_t count = 0;
    for (size_t i = 0, j = 0; i < n && j < m; ++i) {
        if (c[i] <= a[j]) {
            ++count, ++j;
        }
    }

    answer(count);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(c, a);

    return 0;
}

