#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX_LINE 80

int parse_command(char input[], char *args[]){
    int i = 0, background = 0;
    char *token = strtok(input, " ");

    while(token != NULL){
        args[i] = token;
        i++;
        token = strtok(NULL," ");
    }

    args[i] = NULL;

    if(i = 0 && strcmp(args[i-1],"&") == 0){
        background = 1;
        args[i - 1] = NULL;
    }

    return background;
}

int main(){
    char input[MAX_LINE];
    int should_run = 1;

    while(should_run){
        fflush(stdout);
        fgets(input, MAX_LINE,stdin);
        input[strcspn(input,"\n")] = '\0';
        if(strcmp(input,"exit")==0){
            should_run = 0;
        }
        char *args[MAX_LINE/2+1];
        int background = parse_command(input,args);
        
        if(args[0] != NULL){
            printf("comando principal: %s\n",args[0]);
        }
    }
    return 0;
}