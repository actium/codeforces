#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned query(unsigned lb, unsigned ub)
{
    std::cout << "? " << ub - lb;
    while (lb < ub) {
        std::cout << ' ' << ++lb;
    }
    std::cout << std::endl;

    unsigned x;
    std::cin >> x;
    return x;
}

void answer(unsigned x)
{
    std::cout << "! " << 1 + x << std::endl;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    int lb = -1, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;

        (query(mid, ub) != ps[ub] - ps[mid] ? lb : ub) = mid;
    }

    answer(lb);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
