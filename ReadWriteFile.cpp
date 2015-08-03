#include "ReadWriteFile.h"

USING_NS_CC;
ReadWriteFile::ReadWriteFile(){
	
	saveDir = __Dictionary::create();
}
ReadWriteFile::~ReadWriteFile(){
//	savedir->release();
}

void ReadWriteFile::loadData(__String* pkey,char* pData){
//	savedir = CCDictionary::create();
	//保存する配列を作成
	//ccs = CCString::createと同じです。CCString.h内で定義されています。
	//CCArray* ary = CCArray::create(ccs("arytest1"),ccs("arytest2"),NULL);
	//savedir->setObject(ary , "testArray");
	////保存する辞書を作成
	//CCDictionary* dic = CCDictionary::create();
	//dic->setObject(ccs("1"),"dic1");
	//dic->setObject(ccs("2"),"dic2");
	//savedir->setObject(dic , "testDic");
	////保存するCCStringを作成
	//CCString* str = CCString::create("true");
	//savedir->setObject(str , "testBool");

	// add value string
//	savedir->setObject(CCString::create("10"),"dic1");
	//savedir->setObject(CCString::create("20"),"dic2");
//	savedir->setObject(CCString::create("hai nguyen") , "dic3");
	// add value integet
//	savedir->setObject(__Integer::create((int)40),"dic4");
	// add value bool
//	savedir->setObject(CCBool::create(true),"dic5");
	
	

	
	// __String savepath = pData;
	//if(savedir->writeToFile(savepath.getCString())){
	//	CCLOG("save Success:%s" , savepath);
	//}else{
	//	CCLOG("save Failed:%s" , savepath);
	//}
}
void ReadWriteFile::setStringData(__String* pkey,__String* value,__String* pSaveData){
	saveDir->setObject(__String::create(value->getCString()),pkey->getCString());
	saveData(pSaveData);
}
void ReadWriteFile::setIntergerData(__String* pkey,int value,__String* pSaveData){
	saveDir->setObject(__Integer::create((int)value),pkey->getCString());
	saveData(pSaveData);
}
void ReadWriteFile::setBoolData(__String* pkey,bool value,__String* pSaveData){
	saveDir->setObject(__Bool::create(value),pkey->getCString());
	saveData(pSaveData);
}
void  ReadWriteFile::saveData(__String* pSaveData){
	saveDir->writeToFile(pSaveData->getCString());
}

__String* ReadWriteFile::getStringData(__String* pkey,__String* pGetData){
	
	
	CCObject *getdic=getObject(pkey,pGetData);
	__String *valueDic=dynamic_cast<__String*>(getdic) ;
	return valueDic;
}
int ReadWriteFile::getIntergerData(__String* pkey,__String* pGetData){
	
	CCObject *getdic=getObject(pkey,pGetData);
	int valueDic=static_cast<__String*>(getdic)->intValue() ;
	return valueDic;
}
bool ReadWriteFile::getBoolData(__String* pkey,__String* pGetData){
	CCObject *getdic=getObject(pkey,pGetData);
	bool value=dynamic_cast<__String*>(getdic);
	return value;
}
CCObject* ReadWriteFile::getObject(__String* pkey,__String* pGetData){
	CCObject *getObject;
	__Dictionary* parth= __Dictionary::createWithContentsOfFile(pGetData->getCString());
	getObject = parth->objectForKey(pkey->getCString());
	return getObject;
}



std::string* ReadWriteFile::getData(std::string strObjectPosition){
//	//std::string path = FileUtils::getInstance()->fullPathForFilename(strObjectPosition);
//	CCDictionary* savedir = CCDictionary::createWithContentsOfFile(strObjectPosition.c_str());
//
//	CCObject *dic4 = savedir->objectForKey("dic4");
//	int valueDic4= static_cast<CCString*>(dic4)->intValue();
//		
//	CCObject *dic1 = savedir->objectForKey("dic1");
//	CCString *valueDic1=dynamic_cast<CCString*>(dic1) ;
//	
//
//	CCObject *dic5 = savedir->objectForKey("dic5");
////	CCBool *boolobj=dynamic_cast<CCBool*>(dic5);
//
////  log("int =%i  , string= %s , bool=%s",valueDic4,valueDic1->getCString(),boolobj? "true":"false");
////	CCDictionary* save = CCDictionary::create();
//
//	 __String savepath = strObjectPosition;
//	 CCObject *getValue = savedir->objectForKey("dic1");
//	savedir->setObject(CCString::create("thay doi value") , "dic1");
//	savedir->writeToFile(savepath.getCString());

//	auto arrLevels = data.at("testDic").asValueVector();
	/*ValueMap data;
	data = FileUtils::getInstance()->getValueMapFromFile(path);
	
	log("value=%s",data["data"].getDescription().c_str());*/
//	auto get=data.at("data").asValueVector()  ;
	return NULL;
}
