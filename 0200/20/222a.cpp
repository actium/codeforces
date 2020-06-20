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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();
    for (size_t i = k; i < n; ++i) {
        if (a[i] != a[i-1])
            return answer(-1);
    }

    for (size_t i = 0; i < k; ++i) {
        if (a[k-i-1] != a[k-1])
            return answer(k-i);
    }

    answer(0);
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

