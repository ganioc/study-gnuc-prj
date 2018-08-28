#ifndef _CMESSAGE_H_
#define _CMESSAGE_H_
#include <iostream>
#include <vector>
#include <set>
#include "Folder.h"
using namespace std;
class Folder;
class CMessage
{
  friend class Folder;

public:
  CMessage(const string &str = "") : contents(str)
  {
  }
  CMessage(const CMessage &);
  CMessage &operator=(const CMessage &);
  ~CMessage();

  void save(Folder &);
  void remove(Folder &);

  vector<Folder *> get_folders();
  string print_message() { return contents; }
  void debug_print();

private:
  string contents;
  set<Folder *> folders;

  // Add this message to some folders
  void put_Msg_in_Folders(const set<Folder *> &);
  // remove this message from every folder in the folders
  void remove_Msg_from_Folders();

  void addFldr(Folder *f) { folders.insert(f); }
  void remFldr(Folder *f) { folders.erase(f); }
};

#endif