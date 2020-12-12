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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    unsigned c = 0;
    for (size_t l = 0, r = 0; r < n; ) {
        if (a[l] < a[r] && a[r] <= a[l] + k)
            ++c;

        if (a[r] == a[l])
            ++r;
        else
            ++l;
    }

    answer(n - c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

