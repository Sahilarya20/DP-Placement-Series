    #include <iostream>
    #include <vector>
    #include <string>
    #include <climits>
    #include <algorithm>
    using namespace std;

    #define vi vector<int>
    #define pii pair<int, int>
    #define map map<int, vector<int>>
    #define ll long long int
    #define lp(i, a, b) for (ll i = a; i < b; i++)

    long long mod = 998244353;
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            ll n;
            cin >> n;
            string s;
            cin >> s;
            vi a(n, 0);
            long long p = 1;
            if (s[0] == '1')
            {
                a[0] = 1;
            }
            ll check = a[0];

            for (ll i = 1; i < n; i++)
            {
                if (s[i] == '1')
                {
                    check += (i + 1);
                }
                a[i] = check;
                a[i] = a[i] % 2;
            }
            ll ans = 0;
            for (ll i = n - 1; i >= 0; i--)
            {
                if (a[i] == 1)
                {
                    ans += p;
                    ans = ans % mod;
                }
                p = p * 2;
                p = p % mod;
            }

            cout << ans % mod << "\n";
        }
        return 0;
    }