/*
    S=ababba
    add $ sign to end of S $ is less 
    than all elements of S it could be
    any character smaller than elements
    of S. S+='$'
    Suffix Array of S
    6   $
    5   a$
    0   ababba$
    2   abba$
    4   ba$
    1   babba$
    3   bba$
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define size(a) sizeof(a)/sizeof(a[0])
using namespace std;

void judge()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



template<typename T>
auto BuildSuffixArray(T arr,int n)
{ 
    arr.push_back('$');
    n++;
    vector<int> rank(n),index(n);
    {
        vector<pair<char,int>> ci(n);   //ci character and index
        for(int i=0;i<n;i++)
        {
            ci[i] = {arr[i],i};
        }
        sort(ci.begin(),ci.end());
        for(int i=0;i<n;i++) index[i]= ci[i].second;
        rank[index[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(ci[i].first==ci[i-1].first)
            {
                rank[index[i]]=rank[index[i-1]];
            }
            else
            {
                rank[index[i]]=rank[index[i-1]]+1;
            }
        }
    }

    int k=0;

    while((1<<k)<n)
    {
        vector<pair<pair<int,int>,int>> ci(n);
        for(int i=0;i<n;i++)
        {
            ci[i]={{rank[i],rank[i+(1<<k)%n]},i};
        }

        sort(ci.begin(),ci.end());
        for(int i=0;i<n;i++)index[i]=ci[i].second;
        rank[index[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(ci[i].first==ci[i-1].first)
            {
                rank[index[i]]=rank[index[i-1]];
            }
            else
            {
                rank[index[i]] = rank[index[i-1]]+1;
            }
        }
        k++;
    }
    index.erase(index.begin());
    return index;
}

int main()
{
    judge();
    int k;
    vector<int> arr;
    while(cin>>k){arr.push_back(k);}
    
    vector<int> suffixarray = BuildSuffixArray(arr,size(arr));
    for(int i=0;i<size(suffixarray);i++)
    {
        cout<<suffixarray[i]<<" ";//<<arr.substr(suffixarray[i],arr.length()-suffixarray[i])<<endl;
    }
    return 0;   
}