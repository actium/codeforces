#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    for (const unsigned x : a) {
        if (x % 2 == 1)
            return answer("First");
    }

    answer("Second");
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

