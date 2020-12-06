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
    constexpr unsigned oo = 1 << 30;

    const int n = a.size();

    unsigned k = 0;
    for (int i = 0, di = 1, c = 0; c < n; i += di) {
        if (i < 0 || i == n) {
            di = -di;
            ++k;
        } else if (a[i] <= c) {
            a[i] = oo;
            ++c;
        }
    }

    answer(k);
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

