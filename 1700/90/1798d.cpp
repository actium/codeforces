#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    std::cout << "Yes" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a[0] >= 0 || a[n-1] <= 0)
        return no_answer();

    std::vector<int> b;
    for (int i = 0, j = n-1, s = 0; i <= j; ) {
        b.push_back(s < 0 ? a[j--] : a[i++]);
        s += b.back();
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
