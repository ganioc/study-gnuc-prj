#include "CLI11.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    CLI::App app{"My test of CLI."};

    bool bmy_flag;

    app.add_flag("--flag,-f", bmy_flag, "Optional description of flag");

    auto callback = [](int count) {
        cout << "My flag was called " << count << " times." << endl;
    };

    app.add_flag_function("-c", callback, "Optional description of flag cb function");

    int p = 0;
    app.add_option("-p", p, "Parameter");

    vector<int> int_vec;
    app.add_option("--vec", int_vec, "my vector options");

    auto add = app.add_subcommand("add", "Add file(s)");
    bool add_update;
    add->add_flag("-u,--update", add_update, "Add updated files only");
    vector<string> add_files;
    add->add_option("files", add_files, "Files to add");

    add->set_callback([&]() {
        cout << "Adding:";
        if (add_files.empty())
        {
            if (add_update)
            {
                cout << "all updated fles";
            }
            else
            {
                cout << " all files";
            }
        }
        else
        {
            for (auto file : add_files)
            {
                cout << " " << file;
            }
        }
        cout << endl;
    });

    auto commit = app.add_subcommand("commit", "Commit files:");
    string commit_message;
    commit->add_option("-m,--message", commit_message, "A message")->required();

    commit->set_callback([&]() {
        cout << "Commit message: " << commit_message << endl;
    });

    CLI11_PARSE(app, argc, argv);

    cout << "Flag value: " << bmy_flag << endl;
    cout << "Parameter value: " << p << endl;
    cout << "My vector options: " << int_vec.size() << endl;

    return 0;
}
