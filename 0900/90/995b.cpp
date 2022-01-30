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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 1; i < a.size(); i += 2) {
        if (a[i] == a[i-1])
            continue;

        const auto it = std::find(a.begin() + i, a.end(), a[i-1]);
        k += std::distance(a.begin(), it) - i--;
        a.erase(it);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);

    return 0;
}
