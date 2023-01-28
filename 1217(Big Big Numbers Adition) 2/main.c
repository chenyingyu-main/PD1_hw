#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// a=999993 b=737;
void add(char a[], char b[], char res[]){
    int size_a = strlen(a);  //=6
    int size_b = strlen(b);  //=3
    char A[101], B[101], C[102];

    if (size_a > size_b){
        for (int i = 0; i < size_a; ++i) {
            A[i+1]=a[i];
        }
        A[0]='0';
        A[size_a+1]='\0'; //A[7]

        for (int i = size_a; i >= (size_a-size_b)+1 ; i--) {
            B[i]=b[i-(size_a-size_b)-1];
        }
        for (int i = 0; i < (size_a-size_b)+1 ; ++i) {
            B[i]='0';
        }

        C[size_a+1]='\0';
        for (int i = size_a; i >=0 ; --i) {
            C[i]=A[i]+B[i]-'0';
            if (C[i]>'9'){
                C[i]-=10;
                B[i-1]+=1;
            }
        }

        for (int i = 0; C[i]!='\0'; ++i) {
            if (C[i]=='0')continue;
            if (C[i]!='0'){
                for (int j = 0; j < size_a +1; ++j) {
                    res[j]=C[i];
                    i++;
                }break;
            }
        }
    }

    if (size_b > size_a){
        for (int i = 0; i < size_b; ++i) {
            B[i+1]=b[i];
        }
        B[0]='0';
        B[size_b+1]='\0';

        for (int i = size_b; i >= (size_b-size_a)+1 ; i--) {
            A[i]=a[i-(size_b-size_a)-1];
        }
        for (int i = 0; i < (size_b-size_a)+1 ; ++i) {
            A[i]='0';
        }

        C[size_b+1]='\0';
        for (int i = size_b; i >=0 ; --i) {
            C[i]=A[i]+B[i]-'0';
            if (C[i]>'9'){
                C[i]-=10;
                A[i-1]+=1;
            }
        }
        for (int i = 0; C[i]!='\0'; ++i) {
            if (C[i]=='0')continue;
            if (C[i]!='0'){
                for (int j = 0; j < size_b +1; ++j) {
                    res[j]=C[i];
                    i++;
                }break;
            }
        }
    }
}