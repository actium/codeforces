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

int main()
{
    size_t n;
    std::cin >> n;

    unsigned q;
    std::cin >> q;

    std::vector<unsigned> a(n), v(n);
    std::cin >> a;

    integer s = 0;
    for (const unsigned x : a)
        s += x;

    unsigned d = 0, k = 0;
    while (q-- != 0) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned i, x;
            std::cin >> i >> x;
            --i;

            s -= (v[i] == k ? a[i] : d);
            a[i] = x;
            v[i] = k;
            s += a[i];
        }
        if (t == 2) {
            unsigned x;
            std::cin >> x;

            s = integer(x) * a.size();
            d = x;
            ++k;
        }

        answer(s);
    }

    return 0;
}
