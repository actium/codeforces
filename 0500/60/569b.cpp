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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<bool> e(1 + n);
    for (const unsigned x : a) {
        if (x <= n)
            e[x] = true;
    }

    std::vector<bool> v(1 + n);
    for (size_t i = 0, j = 0; i < n; ++i) {
        unsigned& x = a[i];
        if (x > n || v[x]) {
            while (e[++j]);
            x = j;
        }
        v[x] = true;
    }

    answer(a);
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

