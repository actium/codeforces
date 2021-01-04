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

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    unsigned long long k[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == a[i] % 2)
            k[i % 2] += a[i];
    }

    if (k[0] == k[1])
        return answer("Tie");

    answer(k[0] > k[1] ? "Alice" : "Bob");
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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

