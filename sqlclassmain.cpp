#include <stdlib.h>
#include "sqlclass.cpp"


int main(){

    PersonSQL Mysql("FamilyTree", "tcp://127.0.0.1:9903", "matthew", "password");

    Person* personList;
    personList = Mysql.getPersonList();

    while(personList != nullptr){
        cout << personList->firstname << endl;
        personList = personList->next;
    }
    
    return 0;
}

