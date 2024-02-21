#ifndef _DIRECTORY_READER__HPP_
#define _DIRECTORY_READER__HPP_

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

class directory_reader {
    private:
        DIR *dirp;
        struct dirent *dp = nullptr;
    public:
        directory_reader(std::string dir_path);
        std::vector<std::string> read_scripts();
        bool is_dir_opened() const;

        directory_reader(const directory_reader&) = delete;
        directory_reader(directory_reader &&) = delete;
        directory_reader& operator=(const directory_reader &) = delete;
        directory_reader& operator=(directory_reader &&) = delete;

};
#endif // !_DIRECTORY_READER__HPP_