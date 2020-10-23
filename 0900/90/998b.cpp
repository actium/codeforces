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

void solve(const std::vector<unsigned>& a, unsigned b)
{
    const size_t n = a.size();

    std::vector<unsigned> s;
    int d = 0;
    for (size_t i = 0; i < n; ++i) {
        d += (a[i] % 2 == 0 ? 1 : -1);
        if (d == 0 && i+1 < n)
            s.push_back(abs(a[i+1] - a[i]));
    }

    std::sort(s.begin(), s.end());

    unsigned k = 0;
    for (const unsigned x : s) {
        if (x <= b) {
            b -= x;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned b;
    std::cin >> b;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, b);

    return 0;
}

