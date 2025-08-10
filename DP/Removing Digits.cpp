#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> digits;

    int ans = 0;
    int n1;
    while (n > 0)
    {

        ++ans;
        n1 = n;
        while (n1 != 0)
        {
            int digit = n1 % 10;
            digits.push_back(digit);
            n1 /= 10;
        }

        int max_digit = *max_element(digits.begin(), digits.end());
        n = n - max_digit;
        digits.clear();
    }

    cout << ans << endl;

    return 0;
}