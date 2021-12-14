#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;
#include <iostream>

class Person{
    
    public:

        Person(){}
        std::string firstname;
        std::string lastname;
        int age;
        Person* next;
};

class PersonSQL{
       

    public:

        bool insertsuccess;
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res; 

        PersonSQL(std::string schema, std::string tcp, std::string username, std::string password){
        
            try{

                insertsuccess = false;
                driver = get_driver_instance();
                con = driver->connect(tcp, username, password);
                con->setSchema(schema);

            } catch(sql::SQLException &e){

                cout << "# ERR: SQLException in " << __FILE__;
                cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;

            }
            
        }

        bool insertPerson(std::string firstname, std::string lastname, int age){

            try {    

                stmt = con->createStatement();
                insertsuccess = stmt->execute("");
                return true;

            } catch(sql::SQLException &e){

                cout << "# ERR: SQLException in " << __FILE__;
                cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                return false;

            }

        }

            Person* getPersonList(){
            
            try{    
                std::string query = "select * from Persons;";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);

                Person* persFront = nullptr;
                Person* persTemp;

                while (res->next()) {
                    
                    persTemp = new Person();

                    persTemp->firstname = res->getString(2);
                    persTemp->lastname = res->getString(3);
                    persTemp->age = res->getInt(4);
                    persTemp->next = persFront;
                    persFront = persTemp;

                }

                return persFront;

            } catch(sql::SQLException &e){

                cout << "# ERR: SQLException in " << __FILE__;
                cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;

            }

        }

};

// "insert into Persons (LastName, FirstName, Age) values ("matthew3", "Holmes3", 25);"

