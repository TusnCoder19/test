#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;

    cin>>t;

   for(int i=0; i<t; i++)
    {
        int n,k,x,y,max=-1;
        int ss = INT_MAX;
        cin>>n>>k;
        vector<long> a(n);
        for(int j=0 ; j<n; j++)
            cin>>a[j];
        sort(a.begin(), a.end());
        for (int j=0; j<n; j++)
            if(a[j] - k < 0)
            {
                int it = lower_bound(a.begin(), a.end(), k -a[j]) -a.begin();
                if( it ==n) it--;
                while( a[j] + a[it] > k ) it--;

                if(a[j]+a[it] <= k && abs(a[j] -a[it]) < ss && ( a[j]+a[it] ) >= max  && j!= it)
                    {
                        max = a[j] +a[it];
                        ss= abs(a[j] -a[it]);
                        x =j;
                        y =it;

                    }
                }
            else break;
        cout<<a[x]<<" "<<a[y]<<endl;
   }
}
