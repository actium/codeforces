#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned sums[2] = {};
    for (int left = 0, right = n - 1, index = 0; left <= right; ) {
        if (a[left] > a[right]) {
            sums[index] += a[left++];
        } else {
            sums[index] += a[right--];
        }
        index ^= 1;
    }

    answer(sums[0], sums[1]);
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

