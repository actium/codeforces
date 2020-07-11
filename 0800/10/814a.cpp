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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::sort(b.begin(), b.end(), std::greater<unsigned>());

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[i] == 0)
            a[i] = b[j++];
    }

    for (size_t i = 1; i < n; ++i) {
        if (a[i] <= a[i-1])
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(k);
    std::cin >> b;

    solve(a, b);

    return 0;
}

