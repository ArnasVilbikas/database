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
       for (int a=1;a<7;a++)
        {
        string sqlitefile = "database1fx.sqlite";

        sqlite::sqlite db( sqlitefile );

        auto cur = db.get_statement();


        cur->set_sql("select name, level, items from npc where id = ? ;");
        cur->prepare();
        cur->bind(1,a);              //puts a into a placeholder
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
       }
 }

int main()
{
  NPC myobject;
  myobject.values();
    

}