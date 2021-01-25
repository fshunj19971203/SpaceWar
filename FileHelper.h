#include <string>

class FileHelper {
public:
	static bool createDirectory(const std::string& dirpath);
	static bool copyFile(const std::string& filename);
};

