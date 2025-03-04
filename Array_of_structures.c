#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Process {
    char pid[10];
    char process_name[10];
    int process_arrival_time;
    int process_completion_time;
    int process_execution_time;
};

void add_details(struct Process process[], int n);
void print_details(struct Process process[], int n);
void search_pid(struct Process process[], char pid2[10], int n);

void main() {
    int n;
    printf("Enter number of processes\n");
    scanf("%d", &n);

    struct Process *process = malloc(n * sizeof(struct Process));
    add_details(process, n);
    print_details(process, n);

    char pid2[10];
    printf("\nEnter process ID to search for: ");
    scanf("%s", pid2);
    search_pid(process, pid2, n);

    free(process);
    return;
}

void add_details(struct Process process[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter process ID: \n");
        scanf("%s", process[i].pid);

        printf("Enter process name: \n");
        scanf("%s", process[i].process_name);

        printf("Enter process arrival time: \n");
        scanf("%d", &process[i].process_arrival_time);

        printf("Enter process completion time: \n");
        scanf("%d", &process[i].process_completion_time);

        printf("Enter process execution time(ms): \n");
        scanf("%d", &process[i].process_execution_time);
    }
}

void print_details(struct Process process[], int n) {
    for (int j = 0; j < n; j++) {
        printf("\nProcess ID = %s", process[j].pid);
        printf("\nProcess name = %s", process[j].process_name);
        printf("\nProcess arrival time = %d", process[j].process_arrival_time);
        printf("\nProcess completion time = %d", process[j].process_completion_time);
        printf("\nProcess execution time = %d ms", process[j].process_execution_time);
    }
}

void search_pid(struct Process process[], char pid2[10], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(pid2, process[i].pid) == 0) {
            printf("\nProcess found:\n");
            printf("\nProcess ID = %s", process[i].pid);
            printf("\nProcess name = %s", process[i].process_name);
            printf("\nProcess arrival time = %d", process[i].process_arrival_time);
            printf("\nProcess completion time = %d", process[i].process_completion_time);
            printf("\nProcess execution time = %d ms", process[i].process_execution_time);
            return;  // Exit the function once the process is found
        }
    }
    printf("\nProcess with ID %s not found.\n", pid2);
}
