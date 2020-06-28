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

void answer(uint64_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    uint64_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == i + 1)
            continue;

        count += abs(i + 1 - a[i]);
    }

    answer(count);
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

