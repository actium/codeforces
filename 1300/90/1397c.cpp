#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(std::vector<long long>& a)
{
    const long long n = a.size();

    std::cout << "1 1\n";
    std::cout << -a[0] << '\n';
    a[0] = 0;

    if (n == 1) {
        std::cout << "1 1\n";
        std::cout << "0\n";
        std::cout << "1 1\n";
        std::cout << "0\n";
        return;
    }

    std::cout << "2 " << n << '\n';
    for (long long i = 1; i < n; ++i) {
        const long long d = a[i] * (n - 1);
        std::cout << d << ' ';
        a[i] += d;
    }
    std::cout << '\n';

    std::cout << "1 " << n << '\n';
    for (long long i = 0; i < n; ++i) {
        std::cout << -a[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<long long> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

