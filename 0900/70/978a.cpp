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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.crbegin(); it != v.crend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> b;

    bool seen[1000] = {};
    for (size_t i = a.size(); i-- > 0; ) {
        if (!seen[a[i] - 1]) {
            b.push_back(a[i]);
            seen[a[i] - 1] = true;
        }
    }

    answer(b);
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

