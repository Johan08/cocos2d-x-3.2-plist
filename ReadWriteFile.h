#ifndef __READ_WRITE_FILE__
#define __READ_WRITE_FILE__

#include <cocos2d.h>


using namespace cocos2d;
class ReadWriteFile : public cocos2d::Layer
{
public:
	ReadWriteFile();
	~ReadWriteFile();
	void loadData(__String* pkey,char* pData);
	std::string* getData(std::string pData);
	// set data
	void setStringData(__String* pkey,__String* value,__String* pSaveData);
	void setIntergerData(__String* pkey,int value,__String* pSaveData);
	void setBoolData(__String* pkey,bool value,__String* pSaveData);
	// get data
	__String* getStringData(__String* pkey,__String* pGetData);
	int getIntergerData(__String* pkey,__String* pGetData);
	bool getBoolData(__String* pkey,__String* pGetData);
private:
	__Dictionary* saveDir;
	// save data
	void saveData(__String* pSaveData);
	

	CCObject* getObject(__String* pkey,__String* pGetData);
};

#endif // __READ_WRITE_FILE__
