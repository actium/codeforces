#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';

    std::cout << v.size() << '\n';
    for (const auto& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    int s = 0;
    for (const int x : a)
        s += x;

    if (s != 0)
        return answer({ { 1, n } });

    for (size_t i = 0; i < n; ) {
        if (a[i++] != 0)
            return answer({ { 1, i }, { i + 1, n } });
    }

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

