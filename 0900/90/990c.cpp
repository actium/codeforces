#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename Iterator>
int balance(Iterator begin, Iterator end, char p)
{
    int b = 0;
    for (Iterator it = begin; it != end && b >= 0; ++it)
        b += (*it == p ? 1 : -1);

    return b;
}

void solve(const std::vector<std::string>& s)
{
    unsigned f[300001] = {};
    for (const std::string& q : s) {
        const int b = balance(q.begin(), q.end(), '(');
        if (b >= 0)
            ++f[b];
    }

    integer k = 0;
    for (const std::string& q : s) {
        const int b = balance(q.rbegin(), q.rend(), ')');
        if (b >= 0)
            k += f[b];
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
