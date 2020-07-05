#include <iostream>
#include <vector>

#include <climits>
#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a)
{
    int r = INT_MIN;
    for (const int x : a) {
        if (x >= 0) {
            const int z = sqrt(x);
            if (z * z == x)
                continue;
        }

        r = std::max(r, x);
    }

    answer(r);
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

