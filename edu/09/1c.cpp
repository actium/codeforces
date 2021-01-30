#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size(), m = b.size();

    unsigned long long k = 0;
    for (size_t i = 0, j = 0; i < n && j < m; ) {
        if (a[i] < b[j]) {
            ++i;
            continue;
        }
        if (b[j] < a[i]) {
            ++j;
            continue;
        }

        unsigned c = 0;
        for ( ; i < n && a[i] == b[j]; ++i)
            ++c;

        for ( ; j < m && b[j] == a[i-1]; ++j)
            k += c;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

