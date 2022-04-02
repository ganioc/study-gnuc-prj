#include <iostream>
#include <vector>
#include <cstdlib>  // to use exit() funciton
// #include <experimental/filesystem>
#include "init.h"

using namespace std;

static  vector<string> get_dirs(string dir){
    vector<string> collect;
    for (auto &file : fs::directory_iterator(dir))
    {
        cout << file.path() << endl;
        collect.push_back(file.path());
    }
    cout << "what's in collect: " << endl;
    for (vector<string>::iterator iter = collect.begin(); iter != collect.end(); ++iter)
    {
        cout << "* " << *iter << endl;
    }
    return collect;
}

static void check_dirs(string parent_dir, vector<string> dirs)
{
    cout << endl
         << __func__ << "()" << endl;
    cout << "parent dir: " << parent_dir << endl;
    vector<string> collect = get_dirs(parent_dir);

    for (vector<string>::const_iterator iter = dirs.begin();
         iter != dirs.end();
         ++iter)
    {
        cout << "dir: " << *iter << endl;
    }
    vector<string>::iterator  iter = collect.begin();
    try
    {
        for (vector<string>::iterator iter2 = dirs.begin();
             iter2 != dirs.end();
             ++iter2)
        {

            cout << "dir: " << *iter2 << endl;
            string toMatch = parent_dir + *iter2;
            cout << "tomatch: " << toMatch << endl;
            if (count(collect.begin(), collect.end(), toMatch))
            {
                cout << "exists";
            }
            else
            {
                cout << "not exists";
                fs::create_directories(toMatch);
            }
            cout << endl;
        }
    }
    catch (exception e)
    {
        cerr << e.what() << endl;
        exit(1);
        // how to exit? without housekeeping work,
    }
}
static void print_default_values()
{
    cout << endl
         << __func__ << "()" << endl;
    cout << "Default Values:" << endl;
    cout << "Root Dir: " << Nbk::ROOT_DIR << endl;
    cout << "Default Files Dir: " << Nbk::DEFAULT_DIR << endl;
}
// public interface
void Nbk::init_dir(string parent_dir)
{
    cout << endl
         << __func__ << "()" << endl;

    print_default_values();
    vector<string> dirs{Nbk::FILES_DIR,
                        Nbk::SHARE_DIR,
                        Nbk::DATA_DIR};
    check_dirs(parent_dir, dirs);
}