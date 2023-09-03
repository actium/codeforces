/*

a = [1 1 2]

k = 1:
    i = 1:  [1 1 2] -> [1 2] -> [2 2] or [1 3]      A

k = 2:
    i = 1:  [1 1 2] -> [1 1] -> [1 3]
    i = 2:  [1 3] -> [3] -> [4]                     A

k = 3:
    i = 1:  [1 1 2] -> [1 1] -> [1 4]
    i = 2:  [1 4] -> [4] -> [6]
    i = 3:  [6] -> [6]                              B


a = [4 4 4 4]

k = 1:
    i = 1:  [4 4 4 4] -> [4 4 4 4]                  B


a = [1]

k = 1:
    i = 1:  [1] -> []                               A


a = [1 3 2 1 1] = [1 1 1 2 3]

k = 1:
    i = 1:  [1 1 1 2 3] -> [1 1 2 3] -> [1 2 2 3] or [1 1 3 3] or [1 1 2 4]     A

k = 2:
    i = 1:  [1 1 1 2 3] -> [1 1 1 3] -> [1 1 3 3] or [1 1 1 5]
    i = 2:  [1 1 3 3] -> [1 3 3]                                                A
            [1 1 1 5] -> [1 1 5]                                                A

k = 3:
    i = 1:  [1 1 1 2 3] -> [1 1 1 2] -> [1 1 2 4] or [1 1 1 5]
    i = 2:  [1 1 2 4] -> [1 1 4] -> [1 3 4] or [1 1 6]
            [1 1 1 5] -> [1 1 5] -> [1 3 5] or [1 1 7]
    i = 3:  [1 3 4] -> [3 4]                                                    A
            [1 1 6] -> [1 6]                                                    A
            [1 3 5] -> [3 5]                                                    A
            [1 1 7] -> [1 7]                                                    A

k = 4:
    i = 1:  [1 1 1 2 3] -> [1 1 1 2] -> [1 1 2 5] or [1 1 1 6]
    i = 2:  [1 1 2 5] -> [1 1 5] -> [1 4 5] or [1 1 8]
            [1 1 1 6] -> [1 1 6] -> [1 4 6] or [1 1 9]
    i = 3:  [1 4 5] -> [4 5] -> [5 6] or [4 7]
            [1 1 8] -> [1 8] -> [3 8] or [1 10]
            [1 4 6] -> [4 6] -> [6 6] or [4 8]
            [1 1 9] -> [1 9] -> [3 9] or [1 11]
    i = 4:  [4 7] -> [4 7]                                                      B



*/
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    const auto check = [&](unsigned k) {
        for (size_t i = 0; i < k; ++i) {
            if (a[2 * (k - 1) - i] > k - i)
                return false;
        }
        return true;
    };

    unsigned k = 0;
    while (2 * k < n && check(k + 1))
        ++k;

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
