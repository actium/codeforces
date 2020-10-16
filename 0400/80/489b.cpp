#include <algorithm>
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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    unsigned k = 0;
    for (size_t i = 0, j = 0; i < n && j < m; ) {
        const unsigned di = (a[i] < b[j] || a[i] - b[j] <= 1);
        const unsigned dj = (b[j] < a[i] || b[j] - a[i] <= 1);

        k += (di == dj), i += di, j += dj;
    }

    answer(k);
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

