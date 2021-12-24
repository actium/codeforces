#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& h, size_t k)
{
    const size_t n = h.size();

    size_t j = 0;
    for (size_t i = 0; i < k; ++i) {
        for (j = 1; j < n && h[j] <= h[j-1]; ++j);
        if (j == n)
            return answer(-1);

        ++h[--j];
    }

    answer(1 + j);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
