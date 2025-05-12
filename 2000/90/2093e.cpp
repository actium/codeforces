#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const auto check = [&](unsigned x) {
        unsigned c = 0, mex = 0;
        {
            std::vector<bool> v(x+1);
            for (const unsigned e : a) {
                if (e < x)
                    v[e] = true;

                while (v[mex])
                    ++mex;

                if (mex == x) {
                    ++c;
                    v.assign(x+1, false);
                    mex = 0;
                }
            }
        }
        return c >= k;
    };

    unsigned lb = 0, ub = a.size() + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
