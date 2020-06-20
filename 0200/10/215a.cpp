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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    size_t count = 0;

    std::pair<unsigned, unsigned> max = { 0, 0 };
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[j] % a[i] != 0)
                continue;

            if (count == 0 || max.first * a[i] < b[j] * max.second) {
                max.first = b[j];
                max.second = a[i];
                count = 1;
            } else if (max.first * a[i] == b[j] * max.second) {
                ++count;
            }
        }
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

