#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    const auto sorted = [&] {
        for (size_t i = 1; i < n; ++i) {
            if (a[i] < a[i-1])
                return false;
        }
        return true;
    };

    unsigned k = 0;
    for (size_t i = 0; i < n && !sorted(); ++i) {
        if (a[i] > x) {
            std::swap(a[i], x);
            ++k;
        }
    }

    if (sorted())
        return answer(k);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

