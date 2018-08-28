#ifndef _FOLDER_H_
#define _FOLDER_H_
#include <iostream>
#include <set>
#include <vector>

#include "CMessage.h"

using namespace std;

class CMessage;

class Folder
{
  friend class CMessage;

public:
  Folder(){};
  ~Folder();

  Folder(const Folder &);
  Folder &operator=(const Folder &);

  void save(CMessage &);
  void remove(CMessage &);

  void debug_print();

private:
  set<CMessage *> msgs;

  void copy_msgs(const set<CMessage *> &); // add this folder to each message
  void empty_msgs();                       // remove this folder from each message
  void remMsg(CMessage *msg) { msgs.erase(msg); };
  void addMsg(CMessage *msg) { msgs.insert(msg); };
};
#endif