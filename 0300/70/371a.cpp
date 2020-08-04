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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    unsigned c = 0;
    for (size_t i = 0; i < k; ++i) {
        unsigned f[2] = {};
        for (size_t j = i; j < n; j += k) {
            f[0] += (a[j] == 1);
            f[1] += (a[j] == 2);
        }

        c += std::min(f[0], f[1]);
    }

    answer(c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

