#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << 1 + x << ' ' << 1 + y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned lb = 1, ub = n;
    for (size_t i = 0, j = n - 1; i < j; ) {
        if (a[i] == lb) {
            ++lb;
            ++i;
            continue;
        }
        if (a[i] == ub) {
            --ub;
            ++i;
            continue;
        }
        if (a[j] == lb) {
            ++lb;
            --j;
            continue;
        }
        if (a[j] == ub) {
            --ub;
            --j;
            continue;
        }
        return answer(i, j);
    }

    no_answer();
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
