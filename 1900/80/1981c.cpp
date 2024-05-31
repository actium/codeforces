#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n), p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != -1) {
            b[i] = a[i];
            p.push_back(i);
        }
    }

    if (p.empty()) {
        b[0] = 1;
        p.push_back(0);
    }

    for (size_t i = p.front(); i > 0; --i)
        b[i-1] = (b[i] == 1 ? 2 : b[i] / 2);

    for (size_t i = p.back() + 1; i < n; ++i)
        b[i] = (b[i-1] == 1 ? 2 : b[i-1] / 2);

    for (size_t i = 1; i < p.size(); ++i) {
        for (size_t l = p[i-1], r = p[i]; l + 1 < r; ) {
            if (b[l] == b[r]) {
                b[l+1] = (b[l] == 1 ? 2 : b[l] / 2);
                ++l;
                continue;
            }
            if (b[l] > b[r]) {
                b[l+1] = b[l] / 2;
                ++l;
            } else {
                b[r-1] = b[r] / 2;
                --r;
            }
        }
    }

    for (size_t i = 1; i < n; ++i) {
        if (b[i-1] / 2 != b[i] && b[i-1] != b[i] / 2)
            return no_answer();
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
