#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(const std::vector<unsigned>& a, size_t i, size_t j, unsigned x)
{
    while (i < j) {
        if (a[i] == a[j]) {
            ++i, --j;
            continue;
        }
        if (a[i] == x) {
            ++i;
            continue;
        }
        if (a[j] == x) {
            --j;
            continue;
        }
        return false;
    }
    return true;
}

void solve(const std::vector<unsigned>& a)
{
    size_t i = 0, j = a.size() - 1;
    while (i < j && a[i] == a[j])
        ++i, --j;

    answer(check(a, i+1, j, a[i]) || check(a, i, j-1, a[j]));
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
