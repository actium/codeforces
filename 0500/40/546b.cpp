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

void solve(std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    unsigned v = 0, c = 0;
    for (unsigned x : a) {
        if (x <= v) {
            c += v + 1 - x;
            x = v + 1;
        }
        v = x;
    }

    answer(c);
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

