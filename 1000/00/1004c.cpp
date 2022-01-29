#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> u(n+1);
    {
        bool v[100001] = {};
        for (size_t i = n; i-- > 0; ) {
            u[i] = u[i+1] + !v[a[i]];
            v[a[i]] = true;
        }
    }

    integer k = 0;
    {
        bool v[100001] = {};
        for (size_t i = 0; i < n; ++i) {
            if (v[a[i]])
                continue;

            k += u[i+1];
            v[a[i]] = true;
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
