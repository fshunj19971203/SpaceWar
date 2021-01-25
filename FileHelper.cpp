#include "FileHelper.h"
#include "cocos2d.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#endif

#include <string>
#include <stdio.h>
using namespace std;
USING_NS_CC;
bool FileHelper::createDirectory(const std::string& dirpath)
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	//std::string prefix = "/storage/emulated/0/aCardOCR/";
	////如果文件夹不存在
	//int code = mkdir(prefix.c_str(), S_IRWXU);				//则创建
	//CCLOG("%s 创建  %d", prefix.c_str(), code);
	DIR *pDir = opendir(dirpath.c_str()); // 打开目录
	if (!pDir)
	{
		CCLOG("dir not exit..");
		// 创建目录
		int ret = mkdir(dirpath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
		if (ret != 0 && errno != EEXIST)
		{
			CCLOG("mkdir faied..");
			return false;
		}
			CCLOG("mkdir success..");
	}
	return true;
#else
	if ((GetFileAttributesA(dirpath.c_str())) == INVALID_FILE_ATTRIBUTES)
	{
		BOOL ret = CreateDirectoryA(dirpath.c_str(), NULL);
		if (!ret && ERROR_ALREADY_EXISTS != GetLastError())
		{
			return false;
		}
	}
	return true;
#endif
}
bool FileHelper::copyFile(const std::string& filename)
{
	// 资源路径
	std::string sourcePath = FileUtils::getInstance()->fullPathForFilename(filename);
	Data data = FileUtils::getInstance()->getDataFromFile(sourcePath);

	// 可写路径
	std::string destPath = FileUtils::getInstance()->getWritablePath() + filename;
	CCLOG("destPath:%s", destPath.c_str());
	FILE *fp = fopen(destPath.c_str(), "w+");
	if (fp)
	{
		size_t size = fwrite(data.getBytes(), sizeof(unsigned char), data.getSize(), fp);
		fclose(fp);

		if (size > 0)
		{
			return true;
		}
	}
	CCLOG("copy file %s failed.", filename.c_str());
	return false;
}