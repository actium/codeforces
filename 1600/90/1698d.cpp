#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

std::vector<unsigned> query(unsigned lb, unsigned ub)
{
    std::cout << '?' << ' ' << lb << ' ' << ub << std::endl;

    std::vector<unsigned> s(ub - lb + 1);
    std::cin >> s;
    return s;
}

void answer(unsigned x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve(unsigned n)
{
    const auto check = [&](unsigned lb, unsigned ub) {
        unsigned p = 0;
        for (const unsigned x : query(lb, ub))
            p += (x >= lb && x <= ub);

        return p % 2 == 1;
    };

    unsigned lb = 0, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid + 1, ub) ? lb : ub) = mid;
    }

    answer(ub);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
