#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include<cstdlib>
#include <cstring>
#include <queue>
/*
 *
 *
 *
 * <0	The element pointed to by p1 goes before the element pointed to by p2
    0	The element pointed to by p1 is equivalent to the element pointed to by p2
    >0	The element pointed to by p1 goes after the element pointed to by p2
 */
using namespace std;
vector<int> arr[200002];
vector<int> invarr[200002];
 
vector<int> ans;
stack<int> s;
bool visited[200002] ;
void dfs1(int u){
    visited[u]=true;
    for (int i = 0; i <arr[u].size() ; ++i) {
        if(!visited[arr[u][i]]){
            dfs1(arr[u][i]);
        }
    }
    s.push(u);
}
void dfs2(int u){
    visited[u]=true;
    ans.push_back(u);
    for (int i = 0; i <invarr[u].size() ; ++i) {
        if(!visited[invarr[u][i]]){
            dfs2(invarr[u][i]);
        }
    }
}
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main() {
    int N,M,tmp1,tmp2;
    cin>>N>>M;
    for (int i = 0; i <M ; ++i) {
        cin>>tmp1>>tmp2;
        arr[tmp1].push_back(tmp2);
        invarr[tmp2].push_back(tmp1);
    }
    memset(&visited,0, sizeof(visited));
    for (int j = 1; j <=N ; ++j) {
        if(!visited[j]){
            dfs1(j);
        }
    }
    memset(&visited,0, sizeof(visited));
    while(!s.empty()) {
        if(!visited[s.top()]) {
            ans.clear();
            dfs2(s.top());
            s.pop();
 
 
        }else{
            s.pop();
        }
    }
    cout<<endl<<endl;
    qsort(&ans[0], ans.size(),sizeof(int),compare);
    cout<<ans.size()<<endl;
    for (int k = 0; k <ans.size() ; ++k) {
        cout<<ans[k]<<" ";
    }
    return 0;
}