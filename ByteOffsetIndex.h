#ifndef BYTEOFFSETINDEX_H
#define BYTEOFFSETINDEX_H

#include <string>
#include <unordered_map>

using namespace std;

class ByteOffsetIndex {
private:
    unordered_map<string, size_t> index_;

public:
    ByteOffsetIndex();
    void AddOffset(const string& key, size_t offset);
    bool GetOffset(const string& key, size_t& offset);
    bool ContainsKey(const string& key);
    void RemoveKey(const string& key);
};

#endif // BYTEOFFSETINDEX_H

