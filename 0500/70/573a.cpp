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
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned c = 0;
    for (unsigned x : a) {
        while (x % 2 == 0)
            x /= 2;

        while (x % 3 == 0)
            x /= 3;

        if (c != 0 && x != c)
            return answer(false);

        c = x;
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

