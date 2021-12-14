#include <stdlib.h>
#include "sqlclass.cpp"


int main(){

    PersonSQL Mysql("FamilyTree", "tcp://127.0.0.1:3306", "matthew", "9xdfduwu4w");

    Person* personList;
    personList = Mysql.getPersonList();

    while(personList != nullptr){
        cout << personList->firstname << endl;
        personList = personList->next;
    }
    
    return 0;
}

