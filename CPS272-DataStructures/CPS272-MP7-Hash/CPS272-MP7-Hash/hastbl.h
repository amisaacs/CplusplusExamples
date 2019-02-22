/*--------------------------------------------------------------------
//                        hashtbl.h
//--------------------------------------------------------------------


template < class T, class KF >
class HashTbl
{
public:
	HashTbl(int initTableSize);
	~HashTbl();

	void insert(const T &newDataItem) throw (bad_alloc);
	bool remove(KF searchKey);
	bool retrieve(KF searchKey, T &dataItem);
	void clear();

	bool isEmpty() const;
	bool isFull() const;

	void showStructure() const;

private:
	int tableSize;
	List<T> *dataTable;
};
*/