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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    std::multiset<int> s;

    long long h = 0;
    for (const int x : a) {
        if (h + x >= 0) {
            s.insert(x);
            h += x;
            continue;
        }
        if (!s.empty() && x > *s.begin()) {
            h += x - *s.begin();
            s.erase(s.begin());
            s.insert(x);
        }
    }

    answer(s.size());
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
