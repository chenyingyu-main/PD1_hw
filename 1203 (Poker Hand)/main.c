#include <stdio.h>
#define PEOPLE 4
#define CARDS 5

void sort(int a[PEOPLE][CARDS], int b[PEOPLE][CARDS], int low, int high, int k);
int analyze(int b[PEOPLE][CARDS], int a[PEOPLE][CARDS], int k);
void ranking(int c[4], char d[4], int low, int high);

int main(void){
    int rank[PEOPLE][CARDS], suit[PEOPLE][CARDS];
    char a, b; //a refer to rank, b refer to suit

    for (int i = 0; i < PEOPLE; ++i) {
        for (int j = 0; j < CARDS; ++j) {
            scanf("%c%c", &a, &b);
            getchar();
            if (a=='a')rank[i][j]=14;
            if (a=='k')rank[i][j]=13;
            if (a=='q')rank[i][j]=12;
            if (a=='j')rank[i][j]=11;
            if (a=='t')rank[i][j]=10;
            if (a<='9' && a>='1')rank[i][j]=a-'0';
            if(b=='s')suit[i][j]=5;
            if(b=='h')suit[i][j]=3;
            if(b=='d')suit[i][j]=2;
            if(b=='c')suit[i][j]=1;
        }
    }
    //qicksort rank[people][card] and suit[people][card] by their value
    for (int i = 0; i < 4; ++i) {
        sort(rank, suit, 0, 4, i);
    }
    int compare[PEOPLE];
    char figure[PEOPLE];
    // the value of compare (analyze) is their score in the game
    compare[0]=analyze(suit,rank,0);
    compare[1]=analyze(suit,rank,1);
    compare[2]=analyze(suit,rank,2);
    compare[3]=analyze(suit,rank,3);
    figure[0]='A';
    figure[1]='B';
    figure[2]='C';
    figure[3]='D';
    ranking(compare, figure, 0, 3);

    for (int i = 3; i >= 0; --i) {
        printf("%c ", figure[i]);
    }

    return 0;
}

// a refer to rank, b refer to suit in the following function.

void sort(int a[PEOPLE][CARDS], int b[PEOPLE][CARDS], int low, int high, int k){
    //purpose: qicksort rank[people][card] and suit[people][card]

    int i = low, j = high, middle = a[k][(high+low)/2]; // cut in the middle to start sorting
    int temporary;
    while (i<=j){ //so finally, i will be high, and j will be low.
        while (a[k][i] < middle)
            i++;
        while (a[k][j] > middle)
            j--;
        if (i <= j){
            //switch i and j (big to small, small to big)
            temporary=a[k][i];
            a[k][i]=a[k][j];
            a[k][j]=temporary;

            temporary=b[k][i];
            b[k][i]=b[k][j];
            b[k][j]=temporary;

            i++; j--;
        }
        //repeat the step until i is high, j is low (sorting finished)
        if (i < high)
            sort(a, b, i, high, k);
        if (j > low)
            sort(a, b, low, j, k);
        //a[k][4] is the biggest; a[k][0]is the smallest. but not b.
    }
}

int analyze(int b[PEOPLE][CARDS], int a[PEOPLE][CARDS], int k){
    int score;
    int category;
    if (b[k][0]==b[k][1] && b[k][0]==b[k][2] && b[k][0]==b[k][3] && b[k][0]==b[k][4]){
        if ((a[k][0]+1)==a[k][1] && (a[k][1]+1)==a[k][2] &&(a[k][2]+1)==a[k][3] && (a[k][3]+1)==a[k][4]){
            category=9; //straight flush
            score = category*1000 + a[k][4]*10 + b[k][4];
        }
        else{
            category=6; //flush (five cards of the same suit)
            score = category*1000 + a[k][4]*10 + b[k][4];
        }
    }
    else if ((a[k][0]==a[k][1] && a[k][0]==a[k][2] && a[k][0]==a[k][3]) ||
                        (a[k][1]==a[k][2] && a[k][1]==a[k][3] && a[k][1]==a[k][4])){
        category=8; //four-of-a-kind (four cards of the same rank)
        score = category*1000 + a[k][3]*10;
    }
    else if ((a[k][0]==a[k][1] && a[k][0]==a[k][2] && a[k][3]==a[k][4]) ||
                        (a[k][0]==a[k][1] && a[k][2]==a[k][3] && a[k][2]==a[k][4])){
        category=7; //full house (a three-of-a-kind and a pair)
        score = category*1000 + a[k][2]*10 + b[k][2];
    }
    else if ((a[k][0]+1)==a[k][1] && (a[k][1]+1)==a[k][2] &&(a[k][2]+1)==a[k][3] && (a[k][3]+1)==a[k][4]){
        category=5; //straight (five cards with consecutive ranks)
        score = category*1000 + a[k][4]*10 + b[k][4];
    }
    else if ((a[k][0]==a[k][1] && a[k][0]==a[k][2]) ||
                        (a[k][1]==a[k][2] && a[k][1]==a[k][3]) ||
                                 (a[k][2]==a[k][3] && a[k][2]==a[k][4])){
        category=4; //three-of-a-kind (three cards of the same rank)
        score = category*1000 + a[k][2]*10 + b[k][2];
    }
    else if (a[k][0]==a[k][1] && a[k][2]==a[k][3] &&
               a[k][0]!=a[k][2] && a[k][0]!=a[k][4] && a[k][2]!=a[k][4]){
        category=3; //two pairs
        score = category*1000 + 10 * a[k][2] + b[k][2] + b[k][3];
    } else if (a[k][0]==a[k][1] && a[k][3]==a[k][4] &&
               a[k][0]!=a[k][2] && a[k][0]!=a[k][4] && a[k][2]!=a[k][4]){
        category=3; //two pairs
        score = category*1000 + 10 * a[k][3] + b[k][3] + b[k][4];
    } else if (a[k][1]==a[k][2] && a[k][3]==a[k][4] &&
               a[k][0]!=a[k][2] && a[k][0]!=a[k][4] && a[k][2]!=a[k][4]){
        category=3; //two pairs
        score = category*1000 + 10 * a[k][3] + b[k][3] + b[k][4];
    }
    else if (a[k][0]==a[k][1]){
        category=2; //pair
        score = category*1000 + 10 * a[k][1] + b[k][0] + b[k][1];
    }else if (a[k][1]==a[k][2]){
        category=2; //pair
        score = category*1000 + 10 * a[k][2] + b[k][1] + b[k][2];
    }else if (a[k][2]==a[k][3]){
        category=2; //pair
        score = category*1000 + 10 * a[k][3] + b[k][2] + b[k][3];
    }else if (a[k][3]==a[k][4]){
        category=2; //pair
        score = category*1000 + 10 * a[k][4] + b[k][3] + b[k][4];
    }
    else
        score = 1000 + 10 * a[k][4] + b[k][4];

    return score;
}

// c refer to compare, d refer to figure
void ranking(int c[4], char d[4], int low, int high){
    //purpose: make the final ranking from the score

    int i = low, j = high, middle = c[(high+low)/2];
    int temp;
    char temporary;
    while (i<=j){
        while (c[i] < middle)
            i++;
        while (c[j] > middle)
            j--;
        if (i <= j){
            //switch i and j (big to small, small to big)
            temp=c[i];
            c[i]=c[j];
            c[j]=temp;

            temporary=d[i];
            d[i]=d[j];
            d[j]=temporary;

            i++; j--;
        }
        if (i < high)
            ranking(c, d, i, high);
        if (j > low)
            ranking(c, d, low, j);
        //c[k][4] is the biggest; c[k][0]is the smallest.
    }
}
