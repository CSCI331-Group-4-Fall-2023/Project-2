#include "ByteOffsetIndex.h"

using namespace std;

ByteOffsetIndex::ByteOffsetIndex() {
    index_.clear();
}

void ByteOffsetIndex::AddOffset(const string& key, size_t offset) {
    index_[key] = offset;
}

bool ByteOffsetIndex::GetOffset(const string& key, size_t& offset) {
    auto it = index_.find(key);
    if (it != index_.end()) {
        offset = it->second;
        return true;
    }
    return false;
}

bool ByteOffsetIndex::ContainsKey(const string& key) {
    return index_.find(key) != index_.end();
}

void ByteOffsetIndex::RemoveKey(const string& key) {
    auto it = index_.find(key);
    if (it != index_.end()) {
        index_.erase(it);
    }
}
