#include <iostream>
#include <string>
#include <set>
using namespace std;


#include "libsqlite.hpp" //this was taken from the 122com's 6th week(sql) 
//along with libsqlite3.a sqlite3.ddl and sqlite3.h
//
//
#include "NPC_class.cpp"
int database(string idf)
{
        string sqlitefile = "database1fx.sqlite";

        sqlite::sqlite db( sqlitefile );

        auto cur = db.get_statement();


        cur->set_sql("select content, questionA, questionB, questionC from gameprogress where gameprogressID = ? ;");
        cur->prepare();
        cur->bind(1,idf);              //puts id into a placeholder
        cur->step();


        string content = cur->get_text(0);  //puts "content" value from the database to this string
        string questionA = cur->get_text(1); //same for these 3 question values
        string questionB = cur->get_text(2);
        string questionC = cur->get_text(3);


        cout<<content<<endl;
        cout<<questionA<<endl;
        cout<<questionB<<endl;
        cout<<questionC<<endl;
    
            return 1;
}


int main()
{  
        int temp = 0;
        int temp1 = 0;       
        int count = 0;
    
        string id = "0";  //starting id        
        string idc = "1";        
        string con;

        NPC myobject;       //creating an object for the class
        myobject.values();  //calling the void function from the NPC_class

        while (temp!=1)
        {
            database(id);       //calling the function
            string idn;        //creates a new id 
            cin>>idn;         //user enters the new id
            
            if(idn=="A" ||
               idn=="B"||
               idn=="C")
            
            {
                temp=0;    
            }  

            else if(idn=="Q"||
                    idn=="q"||
                    idn=="quit"||
                    idn=="Quit")
             
            {
                      temp=1;
            }
            
            else if(idn=="continue"||
                    idn=="Continue")
                {
                    con="continue";
                    idn="";
                }
            else
            {
                idn="";
            }            
            id=id+idn;        //the new id is added to the old one
            count=count+1;    //i want it to loop 5 times
            if (con=="continue")
                {
                    while(temp1!=1)                      
                        {
                            database(idc);      //calling the function
                            string idcn;        //creates a new id 
                            cin>>idcn;         //user enters the new id

                        if(idcn=="A" ||
                           idcn=="B" ||
                           idcn=="C" ||
                           idcn=="2")                       
                            {
                              temp1=0;
                            }
                        else if(idcn=="Q"||
                                idcn=="q"||
                                idcn=="quit"||
                                idcn=="Quit")
                                {
                                  temp1=1;
                                  temp=1;
                                }
                        else
                            {
                              temp1=0;
                              idcn="";
                            }
                        idc=idc+idcn;        //the new id is added to the old one
                      }
                }
        }
}