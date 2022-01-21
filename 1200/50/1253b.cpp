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
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    int v[1 + 1000000] = {}, k = 0;

    std::vector<size_t> s = { 0 };
    for (size_t i = 0; i < n; ++i) {
        const int x = a[i];
        if (x > 0) {
            if (v[x] < 0)
                return no_answer();

            if (v[x] > 0 && s.back() < v[x])
                return no_answer();

            v[x] = -1;

            ++k;
        } else {
            if (v[-x] >= 0)
                return no_answer();

            v[-x] = i;

            if (--k == 0)
                s.push_back(1 + i);
        }
    }

    if (k != 0)
        return no_answer();

    std::vector<unsigned> c;
    for (size_t i = 1; i < s.size(); ++i)
        c.push_back(s[i] - s[i-1]);

    answer(c);
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
