#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	FILE *f;
    char str[255], name[255];
	int i=0, j=1, c=0, max, pos, k;
	int *command, *lenta;
	
	if (argc != 2) {
		printf("Enter file name.\n");
		scanf("%s", name);
	}
	else
    strcpy(name, argv[1]);
	f = fopen(name, "rb");

	while (f == NULL) {
		printf("Cannot open file. Try again.\n");
		scanf("%s", name);
		f = fopen(name, "r");
	}
    while (!feof(f))
        if (fgetc(f) == '\n')
        c++;
        c++;
    rewind(f);

    command = (int*)malloc(c*sizeof(int));

	while (!feof(f)){
    fgets(str, 255, f);
    i=0;
    while((str[i]=='\t')||(str[i]==' '))
    i++;
    command[j-1]=0;
    if ((str[i]=='m')&&(str[i+3]=='l'))
    command[j-1]=1;
    if ((str[i]=='m')&&(str[i+3]=='r'))
    command[j-1]=2;
    if (str[i] ==  'i')
    command[j-1] = 3;
    if (str[i]=='d')
    command[j-1] = 4;
    if ((str[i]=='p')&&(str[i+6]!='c'))
    command[j-1]=5;
    if (str[i]=='g')
	command[j-1]=6;
	if ((str[i]=='p')&&(str[i+6]=='c'))
    command[j-1]=7;
    if (str[i]=='b')
	command[j-1]=8;
	if (str[i]=='e')
	command[j-1]=9;
	j++;
	}

	i=0;
     lenta = (int*)malloc(1*sizeof(int));
    max=0;
    pos=0;
    lenta[0]=0;
	while(i<(j-1)){


       if (command[i] == 1){
        if (pos==0){
        lenta = (int*)realloc(lenta, (max+2));
        max++;
        for(k=max ;k>0; k--)
        lenta[k]=lenta[k-1];
        pos = 0;
        lenta[0]=0;}
        else pos--;
        i++;
    }


    if (command[i] == 2){
        if (pos==max){
        lenta = (int*)realloc(lenta, (max+2));
        max++;
        lenta[max]=0;}
        pos++;
        i++;

    }
     if (command[i] == 3){
        if (lenta[pos]<255)
        lenta[pos]++;
        else{
        printf("Warning. Reset cell.\n");
        lenta[pos]=0;}
        i++;}
    if (command[i] == 4){
        if (lenta[pos]>0)
        lenta[pos]--;
        else
        printf("Warning. The value of the cell = 0. \n");
        i++;}
    if (command[i] == 5){
        printf("The value of the cell = %d\n", lenta[pos]);
        i++;}
    if (command[i] == 6){
        scanf("%d", &lenta[pos]);
        i++;}
        if (command[i] == 7){
        printf("The value of the call = %c\n", lenta[pos]);
        i++;}
        if (command[i] == 8){
        if (lenta[pos]==0){
                command[i]=-1;
                while (command[i] != 9)
                i++;}
               else i++;}
        if (command[i] == 9){
        if (lenta[pos]==0){
                command[i]=-1;
                i++;}
        else while (command[i] != 8)
                i--;}
        if (command[i]==0)
            i++;
        }
}
