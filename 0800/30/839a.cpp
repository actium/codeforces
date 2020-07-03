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

void solve(const std::vector<size_t>& a, size_t k)
{
    const size_t n = a.size();

    size_t s = 0;
    for (size_t i = 0; i < n; ++i) {
        s += a[i];

        const size_t m = std::min(s, size_t(8));
        if (m >= k)
            return answer(1 + i);

        s -= m, k -= m;
    }

    answer(-1);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

