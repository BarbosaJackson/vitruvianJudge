#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>

namespace {
	std::string getExtension(std::string namefile) {
		std::string ext = "";
		int i;
		for(i = 0; i < namefile.size() && namefile[i] != '.'; i++); i++;
		while(i < namefile.size()){
			ext += namefile[i];
			i++;
		}
		return ext;
	}
	std::vector<std::string> GetDirectoryFiles(const std::string& dir, const std::string extensionFile) {
		std::vector<std::string> files;
		std::shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
		struct dirent *dirent_ptr;
		if (!directory_ptr) {
			std::cout << "Error opening : " << std::strerror(errno) << " " << dir << std::endl;
			return files;
		}

		while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
			if(getExtension(std::string(dirent_ptr->d_name)) == extensionFile) 
				files.push_back(std::string(dirent_ptr->d_name));
		}
		return files;
	}
}

int main(int argv, char **argc) {
	if(argv < 4) return 1;
	const auto& filesInput = GetDirectoryFiles(std::string(argc[1]), "in");
	const auto& filesOutput = GetDirectoryFiles(std::string(argc[2]), "out");
	if((int)filesInput.size() == 0) {
		std::cout << "Error: nothing input file or directory found!" << std::endl;
	}
	if((int)filesOutput.size() == 0) {
		std::cout << "Error: nothing output file or directory found!" << std::endl;
	}
	for (const auto& file : filesInput) {
		std::cout << file << std::endl;
	}
	for(const auto& file : filesOutput) {
		std::cout << file << std::endl;
	}
	return 0;
}	