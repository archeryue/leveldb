#include <iostream>
#include <cassert>

#include "leveldb/db.h"

using namespace std;
using namespace leveldb;

int main(int argc, char** argv) {
    DB* db;
    Options options;
    options.create_if_missing = true;
    Status status = DB::Open(options, "testdb", &db);
    assert(status.ok());

    status = db->Put(WriteOptions(), "hello", "world");
    assert(status.ok());
    string res;
    status = db->Get(ReadOptions(), "hello", &res);
    assert(status.ok());
    cout << res << endl;

    delete db;
    return 0;
}