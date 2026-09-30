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

unsigned reduce(unsigned x)
{
    unsigned k = 0;
    while (x != 1 && x != 4) {
        unsigned y = 0;
        while (x != 0) {
            const unsigned d = x % 10;
            y += d * d;
            x /= 10;
        }
        x = y;
        ++k;
    }
    return x == 1 ? 8 : k % 8;
}

void solve(const std::vector<unsigned>& a)
{
    integer c[9] = {}, k = 0;
    for (const unsigned x : a) 
        k += c[reduce(x)]++;
    
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
