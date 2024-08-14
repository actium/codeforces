#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& v)
{
    std::cout << v.length() << '\n';
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::string s;

    unsigned x = 0;
    for (size_t i = 0, j = n-1; i <= j; ) {
        if (a[i] > x && (a[i] < a[j] || a[j] < x)) {
            s.push_back('L');
            x = a[i++];
            continue;
        }
        if (a[j] > x && (a[j] < a[i] || a[i] < x)) {
            s.push_back('R');
            x = a[j--];
            continue;
        }

        unsigned lc = 0;
        if (a[i] > x) {
            lc = 1;
            for (size_t k = i; k < j && a[k+1] > a[k]; ++k)
                ++lc;
        }

        unsigned rc = 0;
        if (a[j] > x) {
            rc = 1;
            for (size_t k = j; k > i && a[k-1] > a[k]; --k)
                ++rc;
        }

        lc > rc ? s.append(lc, 'L') : s.append(rc, 'R');
        break;
    }

    answer(s);
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
