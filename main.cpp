#include <stdlib.h>
#include <iostream>

// #include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void){

    cout << endl;
    cout << "Running 'SELECT 'Hello World!' » AS _message'..." << endl;

    try {
        
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "matthew", "9xdfduwu4w");
        /* Connect to the MySQL test database */
        con->setSchema("formdata");

        stmt = con->createStatement();
        res = stmt->executeQuery("select * from accounts;");

        while (res->next()) {

        std::string firstname = res->getString("firstname");

        if(!firstname.compare("Jens")){
            cout << "Sir " << firstname << " ";
        } else{
            cout << firstname << " ";   
        }

        cout << res->getString("surname") << endl;
        cout << res->getString(1) <<  " " << res->getString(2) << endl;

        } 

        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;
}

// g++ -o framework -I/usr/local/include -I/usr/local/include/cppconn framework.cpp -lmysqlcppconn