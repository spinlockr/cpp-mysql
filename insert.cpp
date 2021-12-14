#include <stdlib.h>
#include <iostream>

// #include "mysql_connection.h"
//g++ insert.cpp -o insert -lmysqlcppconn 
// g++ -o framework -I/usr/local/include -I/usr/local/include/cppconn framework.cpp -lmysqlcppconn


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void){

    try {
        
        bool insertsuccess = false;

        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "matthew", "9xdfduwu4w");
        con->setSchema("formdata");

        std::string insertstatment = "insert into accounts (firstname, surname, contact) values ('"+firstname+"', '"+surname+"', '"+email+"');";
        stmt = con->createStatement();
        insertsuccess = stmt->execute(insertstatment);
        cout << insertsuccess;

        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return EXIT_SUCCESS;
}

// CREATE TABLE Persons (
//     ID mediumint NOT NULL AUTO_INCREMENT, 
//     LastName varchar(255) NOT NULL,
//     FirstName varchar(255),
//     Age int,
//     PRIMARY KEY (ID)
// );

        // std::string firstname;
        // std::string surname;
        // std::string email;
        // std::string buffer;
        
        // cout << "FIRSTNAME: ";
        // delete stmt;
        // cin >> firstname;

        // cout << "SURNAME: ";
        // cin >> surname;
        
        // cout << "EMAIL: ";
        // cin >> email; 
