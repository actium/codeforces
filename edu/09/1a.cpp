#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<int> c(n + m);
    for (size_t i = 0, j = 0, k = 0; k < n + m; ++k) {
        if (j == m || i < n && a[i] < b[j])
            c[k] = a[i++];
        else
            c[k] = b[j++];
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

