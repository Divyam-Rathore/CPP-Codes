#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[300005];
int main(){
	int i,j,k,n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s);
		int x=0,y=0,z=0;
		bool d=true;
		for(i=0;i<k;i++)
			if(s[i]=='0')x++;
			else if(s[i]=='1')y++;
			else z++;
		if(x>k/2||y>k/2){
			printf("NO\n");
			continue;
		}
		int z0=0,z1=0;
		if(z){
			if(x<k/2)z0=k/2-x;
			if(y<k/2)z1=k/2-y;
		}
		for(i=k;i<n;i++)
			if(s[i]==s[i-k])continue;
			else {
				if((s[i]=='0'&&s[i-k]=='1')||(s[i]=='1'&&s[i-k]=='0')){
					d=false;
					break;
				}
				if(s[i]=='?')s[i]=s[i-k];
				else if(s[i-k]=='?'){
					z--;
					if(s[i]=='0'){
						x++;
						z0--;
					}else if(s[i]=='1'){
						y++;
						z1--;
					}
					if(z0<0||z1<0){
						d=false;
						break;
					}
				}
			}
		printf("%s\n",d?"YES":"NO");
	}
	return 0;
}
