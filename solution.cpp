#include <iostream>
#include <cmath>
using namespace std;

char *reverse(char *tab,char *result,int y1,int y2){
	int i;
	for(i=0;i<=y2-y1;i++){
		*result=tab[y2-i];
		result++;
	}
	return result;
}

char *up(char *tab,char *result,int x1,int x2,int y,int s){
	int i;
	for(i=0;i<=x2-x1;i++){
		*result=tab[(x2-i)*s+y];
		result++;
	}
	return result;
}

char *forward(char *tab,char *result,int y1,int y2){
	int i;
	for(i=0;i<=y2-y1;i++){
		*result=tab[y1+i];
		result++;
	}
	return result;
}

char *down(char *tab,char *result,int x1,int x2,int y,int s){
	int i;
	for(i=0;i<=x2-x1;i++){
		*result=tab[(x1+i)*s+y];
		result++;
	}
	return result;
}

bool check(int x1,int x2,int y1,int y2){
	return x1<=x2 && y1<=y2;
}

void main_loop(char *tab,int x1,int x2,int y1,int y2,int size){
	char result[size*size+1];
	char *result_p=result;
	int ri=0;
	int add;
	do {
		result_p=reverse(&tab[x2*size],result_p,y1,y2);
		x2--;
		result_p=up(tab,result_p,x1,x2,y1,size);
		y1++;
		result_p=forward(&tab[x1*size],result_p,y1,y2);
		x1++;
		result_p=down(tab,result_p,x1,x2,y2,size);
		y2--;
	} while (x1<x2 && y1<y2);
	if(x1==x2 && y1==y2){
		*result_p=tab[y1*size+x1];
		result_p++;
	}
	*result_p='\0';
	cout << result;
}

int len(char *s){
	int i=0;
	while(s[i++]!='\0');
	return i-1;
}


int main(int argc, char **argv){
	std::ios_base::sync_with_stdio(false);
	int size=sqrt(len(argv[1]));
	main_loop(argv[1],0,size-1,0,size-1,size);
	return 0;
}
