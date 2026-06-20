#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

typedef struct contact{
    char name[100];
    char phoneNumber[100];
    struct contact *closeFriend;
}contact;

int phone_sum(char *phoneNumber){
    int sum=0;
    for(int i=0; phoneNumber[i]!='\0'; i++){
        if(phoneNumber[i]>='0' && phoneNumber[i]<='9') sum+=phoneNumber[i]-'0';
    }
    return sum;
}

contact *contact_name(contact *contacts, int n, char *name) {
    for(int i=0; i<n; i++){
        if(strcmp(contacts[i].name, name)==0) return &contacts[i];
    }
    return NULL;
}

int friend_phone(contact *c){
    if(c==NULL || c->closeFriend==NULL) return -1;
    return phone_sum(c->closeFriend->phoneNumber);
}

void sort(contact *contacts, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            int sum1=phone_sum(contacts[j].phoneNumber);
            int sum2=phone_sum(contacts[j+1].phoneNumber);
            int friend_sum1=friend_phone(&contacts[j]);
            int friend_sum2=friend_phone(&contacts[j+1]);
            if(sum1>sum2){
                contact temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }
            else if(sum1==sum2){
                if(friend_sum1!=-1 && friend_sum2!=-1){
                    if(friend_sum1>friend_sum2){
                        contact temp=contacts[j];
                        contacts[j]=contacts[j+1];
                        contacts[j+1]=temp;
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    contact *contacts = (contact*)malloc(n * sizeof(contact));
    for(int i=0; i<n; i++){
        scanf("%s %s", contacts[i].name, contacts[i].phoneNumber);
        contacts[i].closeFriend=NULL;
    }
    int c;
    scanf("%d", &c);
    for(int i=0; i<c; i++){
        char name1[105], name2[105];
        scanf("%s %s", name1, name2);
        contact *contact1=contact_name(contacts, n, name1);
        contact *contact2=contact_name(contacts, n, name2);
        if(contact1!=NULL && contact2!=NULL) {
            contact1->closeFriend=contact2;
            contact2->closeFriend=contact1;
        }
    }
    sort(contacts, n);
    for(int i=0; i<n; i++){
        printf("Contact #%d\n\n", i+1);
        printf("Name : %s\n", contacts[i].name);
        printf("Phone Number : %s\n", contacts[i].phoneNumber);
        printf("-------------------------\n\n");
    }
    free(contacts);
    return 0;
}