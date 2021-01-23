#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    unsigned long long c = 0, r = 0;
    for (const unsigned q : a) {
        if (r + q < k && r != 0) {
            c += 1;
            r = 0;
        } else {
            r += q;
            c += r / k;
            r %= k;
        }
    }

    answer(c + (r != 0));
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

