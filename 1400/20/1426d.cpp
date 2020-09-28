#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a)
{
    unsigned k = 0;

    std::set<long long> s;
    long long p = 0;
    for (const int x : a) {
        p += x;
        if (p == 0 || s.count(p) != 0) {
            ++k;
            s.clear();
            p = x;
        }
        s.insert(p);
    }

    answer(k);
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

