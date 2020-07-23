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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const size_t k = std::max_element(a.cbegin(), a.cend()) - a.cbegin();
    for (size_t i = 1; i < k; ++i) {
        if (a[i] < a[i-1])
            return answer(false);
    }
    for (size_t i = k+2; i < n; ++i) {
        if (a[i] > a[i-1])
            return answer(false);
    }

    answer(true);
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

