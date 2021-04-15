/*  Apr 15 
    simple example how use list , and dymamicly memory
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 128
char* s_gets(char *st,int n){
    char *pst=fgets(st,n,stdin);
    if(pst!=NULL){
        if(pst=strchr(st,'\n'))
            *pst='\0';
        else 
            while(getchar()!='\n')
                continue;      
    } else return NULL;
    return st;
}
typedef struct _employee{
    char* name;
    char* surname;
    int age;
    double salary;
    char gender;
    struct _employee*next;
} employee;
employee* create_node(char*name,char*surname,int age,double salary,char gender){
    employee*new_node;
    new_node=(employee*)malloc(sizeof(employee));
    new_node->next=NULL;
    new_node->name=(char*)malloc(sizeof(name)+1);
    strcpy(new_node->name,name);
    new_node->surname=(char*)malloc(sizeof(surname)+1);
    strcpy(new_node->surname,surname);
    new_node->age=age;
    new_node->salary=salary;
    new_node->gender=gender;
    return new_node;
}
void free_list(employee*head){
    employee*current;
    while(head!=NULL){
        current=head;
        head=head->next;
        free(current->name);
        free(current->surname);
        free(current);
    }
}
void show_list(employee*current){
    printf("LIST has next values\n");
    while(current!=NULL){
        printf("%s %s %c %d years old salary : %lf\n",current->name,current->surname,current->gender,
        current->age,current->salary);
        current=current->next;
    }
}
void list(void){
    employee *head=NULL,*current,*temp;
    char name[SIZE];
    char surname[SIZE];
    double salary;
    int age;
    char gender,stop;
    printf("This program creates and shows a list of employees + dynamicly memory allocate\n");
    while(true){
    puts("Input name : ");
    s_gets(name,128);//fgets(name,128,stdin);
    puts("Surname : ");
    s_gets(surname,128);//fgets(surname,128,stdin);
    puts("Gender , age and salary");
    scanf("%c %d %lf",&gender,&age,&salary);
    while(getchar()!='\n');//fflush(stdin);
    current=create_node(name,surname,age,salary,gender);
    if(head==NULL)
        head=current;
    else 
        temp->next=current;    
        temp=current;
        printf("add next employee? (Y/N): ");
        scanf(" %c",&stop);
        while(getchar()!='\n');
        if(stop=='N')
            break;        
    }
    current=head;
    show_list(current);
    free_list(head);
}
int main(void){
    list();
    return 0;
}
