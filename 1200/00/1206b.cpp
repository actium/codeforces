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

void solve(const std::vector<int>& a)
{
    long long k = 0, n = 0, z = 0;
    for (const int x : a) {
        if (x < 0) {
            k -= x + 1, ++n;
        }
        if (x == 0) {
            ++k, ++z;
        }
        if (x > 0) {
            k += x - 1;
        }
    }

    if (n % 2 != 0 && z == 0)
        k += 2;

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

