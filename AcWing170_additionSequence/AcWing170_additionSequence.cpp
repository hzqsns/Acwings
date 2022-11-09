#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;


int n;
int path[N];

//u表示第几层，max_depth表示最大层数
bool dfs(int u,int max_depth) {
    if(u == max_depth) return path[u-1] == n;
    //这里不写成u > max_depth的写法
    //因为那样会继续多迭代一层，时间复杂度大大增加

    bool st[N] = {0};
    for(int i = u - 1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            int s = path[i] + path[j];
            if(s > n || st[s] || s <= path[u-1]) continue;
            path[u] = s;
            st[s] = true;
            if(dfs(u+1,max_depth)) return true;
            st[s] = false;
            path[u] = 0;
        }
    }
    return false;
}

int main(){
    
    while(cin>>n,n){
        path[0] = 1;
        int depth = 1;
        while(!dfs(1,depth)) depth++;
        for(int i = 0;i < depth;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}