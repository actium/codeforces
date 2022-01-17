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
    constexpr const char* s[2] = { "first", "second" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<int>& a)
{
    unsigned long long s1 = 0, s2 = 0;

    std::vector<unsigned> v1, v2;
    for (const int x : a) {
        if (x > 0) {
            v1.push_back(x);
            s1 += x;
        } else {
            v2.push_back(-x);
            s2 += -x;
        }
    }

    if (s1 != s2)
        return answer(s1 < s2);

    if (v1 != v2)
        return answer(v1 < v2);

    answer(a.back() < 0);
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
