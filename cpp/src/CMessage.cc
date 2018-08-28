#include <iostream>
#include <set>
#include "CMessage.h"

using namespace std;

CMessage::CMessage(const CMessage &m) : contents(m.contents), folders(m.folders)
{
    put_Msg_in_Folders(folders);
}

CMessage &CMessage::operator=(const CMessage &rhs)
{
    if (&rhs != this)
    {
        remove_Msg_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;

        put_Msg_in_Folders(rhs.folders);
    }
    return *this;
}
void CMessage::remove_Msg_from_Folders()
{
    for (set<Folder *>::const_iterator beg = folders.begin();
         beg != folders.end();
         ++beg)
    {
        (*beg)->remMsg(this);
    }
}

void CMessage::put_Msg_in_Folders(const set<Folder *> &rhs)
{
    for (set<Folder *>::const_iterator beg = rhs.begin();
         beg != rhs.end();
         ++beg)
    {
        (*beg)->addMsg(this);
    }
}
void CMessage::save(Folder &rhs)
{
    folders.insert(&rhs);
    rhs.addMsg(this);
}
void CMessage::remove(Folder &rhs)
{
    folders.erase(&rhs);
    rhs.remMsg(this);
}

vector<Folder *> CMessage::get_folders()
{
    return vector<Folder *>(folders.begin(), folders.end());
}

void CMessage::debug_print()
{
    cout << "Message:\n\t" << contents << endl;
    cout << "Appears in " << folders.size() << " Folders" << endl;
    cout << "" << endl;
}

CMessage::~CMessage()
{
    remove_Msg_from_Folders();
}