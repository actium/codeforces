#include <iostream>
#include <numeric>
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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<int> b;
    b.push_back(a[0]);
    for (size_t i = 1; i < n; ++i) {
        int& last = b.back();
        if ((last ^ a[i]) < 0) {
            b.push_back(a[i]);
        } else {
            last = std::max(last, a[i]);
        }
    }

    answer(std::accumulate(b.cbegin(), b.cend(), 0ll));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

