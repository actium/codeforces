#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<int>& a, const std::vector<int>& b, size_t k, size_t m)
{
    answer(a[k-1] < b[b.size()-m]);
}

int main()
{
    size_t na, nb;
    std::cin >> na >> nb;

    size_t k, m;
    std::cin >> k >> m;

    std::vector<int> a(na);
    std::cin >> a;

    std::vector<int> b(nb);
    std::cin >> b;

    solve(a, b, k, m);

    return 0;
}

