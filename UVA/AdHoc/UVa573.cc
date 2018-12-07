#include<bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int h,u,d,f;
        scanf("%d %d %d %d", &h, &u, &d, &f);
        if(!h) return 0;
        int init = 0, aclimbing = 0, asliding = 0, day = 1;
        bool success = true;
        while(true){
           int dis = u * 100 - u * f * (day - 1);
           if(dis <= 0) dis = 0;
           aclimbing = dis + init;
           if(aclimbing > h * 100) break;
           asliding = aclimbing - d * 100;
           if(asliding < 0){
               success = false;
               break;
           }
           init = asliding;
           day++;
        }
        if(success) printf("success on day %d\n",day);
        else printf("failure on day %d\n",day);
    }
}
