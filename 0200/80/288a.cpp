#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, size_t k)
{
    if (n == 1 && k == 1)
        return answer("a");

    if (k == 1 || k > n)
        return no_answer();

    std::string s;
    for (size_t i = 0; i < n - k + 2; ++i)
        s.push_back('a' + i % 2);

    for (size_t i = 2; i < k; ++i)
        s.push_back('a' + i);

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

