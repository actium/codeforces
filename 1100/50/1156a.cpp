#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    if (x == oo) {
        std::cout << "Infinite" << '\n';
    } else {
        std::cout << "Finite" << '\n';
        std::cout << x << '\n';
    }
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] + a[i-1] == 5)
            return answer(oo);

        if (a[i] + a[i-1] == 4)
            k += 4;

        if (a[i] + a[i-1] == 3) {
            k += 3;

            if (i > 1 && a[i-2] == 3)
                --k;
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
