#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> x(n);
    for (size_t i = 0, s = 0; i < n; ++i) {
        x[i] = a[i] - s;
        s += x[i];
    }

    const auto check = [&](unsigned k) {
        int s = 0;
        for (size_t i = 0; i < n; ++i) {
            s += x[i % k];
            if (s < 0 || s != a[i])
                return false;
        }
        return true;
    };

    std::vector<unsigned> v;
    for (unsigned k = 1; k <= n; ++k) {
        if (check(k))
            v.push_back(k);
    }

    answer(v);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

