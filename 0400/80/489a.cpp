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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, size_t>> x;
    for (size_t i = 0; i < n; ++i) {
        const size_t j = std::min_element(a.begin() + i, a.end()) - a.begin();
        if (a[j] < a[i]) {
            x.emplace_back(i, j);
            std::swap(a[i], a[j]);
        }
    }

    answer(x);
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

