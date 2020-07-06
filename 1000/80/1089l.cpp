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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> c(k, -1), d;
    for (size_t i = 0; i < n; ++i) {
        const size_t t = a[i] - 1;
        if (c[t] == -1) {
            c[t] = i;
            continue;
        }

        const size_t x = c[t];
        if (b[i] > b[x]) {
            c[t] = i;
            d.push_back(x);
        } else {
            d.push_back(i);
        }
    }

    std::sort(d.begin(), d.end(), [&b](size_t x, size_t y) { return b[x] < b[y]; });

    unsigned long long s = 0;
    for (size_t i = 0, j = 0; i < k; ++i) {
        if (c[i] == -1) {
            const size_t x = d[j++];
            s += b[x];
        }
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b, k);

    return 0;
}

