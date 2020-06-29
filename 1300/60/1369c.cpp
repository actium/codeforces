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

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a, std::vector<unsigned>& w)
{
    const size_t n = a.size();
    const size_t k = w.size();

    std::sort(a.rbegin(), a.rend());
    std::sort(w.begin(), w.end());

    long long s = 0;

    size_t j = 0;
    for (size_t i = 0; i < k; ++i) {
        s += a[i];

        if (--w[i] == 0) {
            s += a[i];
            j = i + 1;
        }
    }
    for (size_t i = k; i < n; ) {
        s += a[i + w[j] - 1];
        i += w[j++];
    }

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<unsigned> w(k);
    std::cin >> w;

    solve(a, w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

