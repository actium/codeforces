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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<unsigned> c(n);
    std::vector<bool> v(n);
    for (size_t i = 0, j = 0; i < n; ++i) {
        const unsigned x = b[i];
        if (v[x-1])
            continue;

        while (j < n) {
            ++c[i];
            v[a[j]-1] = true;

            if (a[j++] == x)
                break;
        }
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

