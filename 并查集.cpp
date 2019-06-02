#include<cstdio>

const int MAXN = 100;
int par[MAXN];

// 初始化n个元素
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
}

// 查询树的根
int find(int x){
    if(par[x] == x){
        return x;
    }
    return (par[x] = find(par[x]));  // 路径压缩
}

// 合并x和y所属的集合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    par[x] = y;
}

// 判断x和y是否属于同一个集合
bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
     
    return 0;
}
