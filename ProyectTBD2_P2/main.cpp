#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "DBAPI.h"

using namespace std;

char database_to_use[50];

int main(int argc, char **argv){
    char *option = new char[500];
    string opt;
    do{
        system("clear");
        cout << "DBCLI > ";
        cin.getline(option, 500, '\n');
        char* op1 = strtok(option, " ");
        char* op2 = strtok(NULL, " ");
        char* op3 = strtok(NULL, " ");
        char* op4 = strtok(NULL, " ");
        char* op5 = strtok(NULL, " ");
        char* op6 = strtok(NULL, " ");
        if(!strcmp(op1, "create") && !strcmp(op2, "database")){
            if(atoi(op4) > 512){
                cout << "Tamano maximo de DB es de 128 MB" << endl;
            }else{
                int size_in_bytes = get_size_in_bytes(atoi(op4), op5);
                create_database(size_in_bytes, op3);
                format_database(size_in_bytes, op3);
                cout << "La base de datos se creo con exito!" <<endl;
            }
        }
        else if(!strcmp(op1, "drop") && !strcmp(op2, "database"))
        {
            delete_database(op3);
        }
        else if(!strcmp(op1, "use") && !strcmp(op2, "database"))
        {
            strcpy(database_to_use, op3);
            string duses = "Usaras esta base de datos! ";
            cout <<duses<<endl;
        }
        else if(!strcmp(op1, "create") && !strcmp(op2, "table"))
        {
            create_table(database_to_use, op3, get_values(op4), get_values(op5), get_values(op6));
            string tuses = "Tabla creada!" ;
            cout <<tuses<<endl;
        }
        else if(!strcmp(op1, "drop") && !strcmp(op2, "table"))
        {
            drop_table(database_to_use, op3);
            cout<<"Tabla eliminada!"<<endl;
        }
        else if(!strcmp(op1, "show") && !strcmp(op2, "tables"))
        {
            show_tables(database_to_use);
        }
        else if(!strcmp(op1, "insert"))
        {
            insert_register(database_to_use, op2, get_values(op3), get_values(op4));
            //cout<<"Registro agregado exitosamente!"<<endl;
        }
        else if(!strcmp(op1, "select"))
        {
            select_show(database_to_use, get_values(op2), get_values(op3), get_values(op4));
        }
        else if(!strcmp(op1, "update"))
        {
            update_register(database_to_use, op2, get_values(op3), get_values(op4), get_values(op5));
            cout<<"Registro actualizado exitosamente!"<<endl;
        }
        else if(!strcmp(op1, "delete"))
        {
            delete_register(database_to_use, op2, get_values(op3));
            cout<<"Registro eliminado exitosamente!"<<endl;
        }
        else if(!strcmp(op1, "help"))
        {
            cout << "-----------------------------------------------------------" << endl;
            cout << "Create database ---> create database name size type || type ex=kb, mb, gb" << endl;
            cout << "Drop database ---> drop database name" << endl;
            cout << "Select database to use ---> use database name" << endl;
            cout << "Create table ---> create table name -columns=col1,col2,col3 -type=int,double,char(50) -key=col1" << endl;
            //create table mayore -columns=id,nombre,numero -type=int,char(50),int -key=id
            cout << "Drop table ---> drop table table_name" << endl;
            cout << "Show all database tables ---> show tables" << endl;
            cout << "Insert ---> insert table_name -columns=col1,col2,col3 -values=value1,value2,value3" << endl;
            cout << "Update ---> update table_name -columns=col1,col2 -values=1,2 -where=col1<>1" << endl;
            cout << "Delete ---> delete table_name -where=col<>cond" << endl;
            cout << "Select ---> select -table=table_name -columns=col1,col2 || optional -where=col<>cond" << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
        else if(!strcmp(op1, "exit"))
        {
            break;
        }
        getchar();
        strcpy(option, " ");
    }while(true);
}