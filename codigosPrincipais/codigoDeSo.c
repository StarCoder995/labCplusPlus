#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS (MAX_LINE / 2 + 1)
#define HISTORY_SIZE 10

char history[HISTORY_SIZE][MAX_LINE];
int history_count = 0;

void add_history(char command){
    int index = history_count & HISTORY_SIZE;
    strcpy(history[index],command);
    history_count++;
}

void show_history(){
    int start, i, index;

    if(history_count < HISTORY_SIZE){
        start = 1;
    } else{
        start = history_count - HISTORY_SIZE + 1;
    }
    for(i = history_count;i>= start;i--){
        index = (i - 1) % HISTORY_SIZE;
        printf("%d %s\n",i,history[index]);
    }
}

int get_last_command(char command[]) {
    int index;

    if (history_count == 0) {
        return 0;
    }
    index = (history_count - 1) % HISTORY_SIZE;
    strcpy(command, history[index]);
    return 1;
}

 

int get_command_by_number(int number, char command[]) {
    int start;
    int index;

    if (history_count < HISTORY_SIZE) {
        start = 1;
    } else {
        start = history_count - HISTORY_SIZE + 1;
    }
    if (number < start || number > history_count) {
        return 0;
    }
    index = (number - 1) % HISTORY_SIZE;

    strcpy(command, history[index]);
    return 1;
}

int parse_command(char input[], char *args[]){
    int i = 0;

    int background = 0;

    char *token = strtok(input, " \t");

 

    while (token != NULL && i < MAX_ARGS - 1) {

        args[i] = token;

        i++;

        token = strtok(NULL, " \t");

    }

 

    args[i] = NULL;

 

    if (i > 0 && strcmp(args[i - 1], "&") == 0) {

        background = 1;

        args[i - 1] = NULL;

    }

 

    return background;

}

 

void execute_command(char *args[], int background) {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Erro ao criar processo-filho\n");
    }

    else if (pid == 0) {
        execvp(args[0], args);
        perror("Erro ao executar comando");
        exit(1);
    }
    else {
        if (!background) {
            wait(NULL);
        }
    }
}
void execute_command(char *args[], int background){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("Erro ao criar processo filho\n");
    }
    else if(pid == 0){
        execvp(args[0],args);
        printf("Erro ao executar comando\n");
    }
    else{
        if(background){
            wait(NULL);
        }
    }
}

int main(void){
    char input[MAX_LINE];
    int should_run = 1;

    while(should_run){
        printf("osh>");
        fflush(stdout);
        fgets(input, MAX_LINE,stdin);
        input[strcspn(input,"\n")] = '\0';
        if(strcmp(input,"exit")==0){
            should_run = 0;
        }
        char *args[MAX_LINE/2+1];
        int background = parse_command(input,args);
        
        if(args[0] != NULL){
            execute_command(args,background);
        }
    }
    return 0;
}