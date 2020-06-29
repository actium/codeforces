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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    int max_sum = 0;
    for (int max = 1; max <= 30; ++max) {
        int sum = 0;
        for (size_t i = 0; i < n; ++i) {
            if (a[i] > max)
                sum = 0;
            else
                sum = std::max(sum + a[i], a[i]);

            max_sum = std::max(max_sum, sum - max);
        }
    }

    answer(max_sum);
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
    test_case();

    return 0;
}

