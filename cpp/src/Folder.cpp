#include "Folder.h"

Folder::Folder(const Folder &f)
{
    copy_msgs(f.msgs);
}
void Folder::copy_msgs(const set<CMessage *> &m)
{
    for (set<CMessage *>::const_iterator beg = m.begin();
         beg != m.end();
         ++beg)
    {
        (*beg)->save(*this);
    }
}
Folder &Folder::operator=(const Folder &f)
{
    if (&f != this)
    {
        empty_msgs();
        copy_msgs(f.msgs);
    }
    return *this;
}
void Folder::empty_msgs()
{
    set<CMessage *>::const_iterator beg = msgs.begin();

    while (beg != msgs.end())
    {
        set<CMessage *>::const_iterator next;
        next = beg;
        ++next;
        (*beg)->remove(*this);
        beg = next;
    }
}
Folder::~Folder() { empty_msgs(); }

void Folder::save(CMessage &m)
{
    msgs.insert(&m);
    m.addFldr(this);
}
void Folder::remove(CMessage &m)
{
    msgs.erase(&m);
    m.remFldr(this);
}
void Folder::debug_print()
{
    cout << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (set<CMessage *>::const_iterator beg = msgs.begin();
         beg != msgs.end(); ++beg)
    {
        cout << "Message " << ctr++ << ":\n\t"
             << (*beg)->print_message() << endl;
    }
    cout << "" << endl;
}