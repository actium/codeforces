#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << "YES" << '\n';

    std::cout << x.size() << '\n';
    std::cout << x << '\n';

    std::cout << y.size() << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned f[200001] = {};
    for (const unsigned x : a) {
        if (++f[x] == 3)
            return no_answer();
    }

    std::vector<unsigned> b1;
    for (unsigned i = 0; i <= 200000; ++i) {
        if (f[i] > 0) {
            b1.push_back(i);
            --f[i];
        }
    }

    std::vector<unsigned> b2;
    for (unsigned i = 200000; ~i; --i) {
        if (f[i] > 0) {
            b2.push_back(i);
            --f[i];
        }
    }

    answer(b1, b2);
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

