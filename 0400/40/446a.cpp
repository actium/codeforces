#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();
    if (n == 1)
        return answer(1);

    std::vector<unsigned> p(n, 1), s(n, 1);
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            p[i] = p[i-1] + 1;

        if (a[n-i] > a[n-i-1])
            s[n-i-1] = s[n-i] + 1;
    }

    unsigned k = std::max(p[n-2], s[1]) + 1;
    for (size_t i = 1; i + 1 < n; ++i) {
        if (a[i-1] + 1 < a[i+1])
            k = std::max(k, p[i-1] + s[i+1] + 1);
        else
            k = std::max(k, std::max(p[i-1], s[i+1]) + 1);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
