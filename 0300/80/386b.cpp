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

void solve(std::vector<unsigned>& t, unsigned d)
{
    const size_t n = t.size();

    std::sort(t.begin(), t.end());

    unsigned k = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        while (t[j] - t[i] > d)
            ++i;

        k = std::max<unsigned>(k, j - i + 1);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    unsigned d;
    std::cin >> d;

    solve(t, d);

    return 0;
}
