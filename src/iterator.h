#ifndef SSDB_ITERATOR_H_
#define SSDB_ITERATOR_H_

#include <inttypes.h>
#include <string>
#include "rocksdb/iterator.h"
#include "rocksdb/slice.h"
#include "util/bytes.h"

class Iterator{
	public:
		enum Direction{
			FORWARD, BACKWARD
		};
	private:
		rocksdb::Iterator *it;
		std::string end;
		uint64_t limit;
		bool is_first;
		int direction;
	public:
		Iterator(rocksdb::Iterator *it,
				const std::string &end,
				uint64_t limit,
				Direction direction=Iterator::FORWARD);
		~Iterator();
		bool skip(uint64_t offset);
		bool next();

		Bytes key(){
			return it->key();
		}

		Bytes val(){
			return it->value();
		}
};

#endif
