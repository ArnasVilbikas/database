#include <iostream>
#include <string>
using namespace std;

#include "libsqlite.hpp"

class NPC{
  private:
    string name;
    int level;
    string items;
    string namearray [6]{};//creates an array of names
    int levelarray [6]{};//creates an array of levels
    string itemsarray[6]{};//creates an array of items
  public:
    void values();

};
void NPC::values()
 {
                string sqlitefile = "database1fx.sqlite";
       for (int a=0;a<6;a++)
        {

        int c=a+1;
        sqlite::sqlite db( sqlitefile );

        auto cur = db.get_statement();

        cur->set_sql("select name, level, items from npc where id = ? ;");
        cur->prepare();
        cur->bind(1,c);              //puts a into a placeholder
        cur->step();
        string npcname = cur->get_text(0);
        int npclevel = cur->get_int(1);
        string npcitems = cur->get_text(2);
        
        name=npcname;
           
           namearray[a]=name; 
        level=npclevel;
           levelarray[a]=level;
        items=npcitems;
           itemsarray[a]=items;
        //cout<<namearray[a]<<endl; //uncomment if you want to print out the array of names
       }
 }
