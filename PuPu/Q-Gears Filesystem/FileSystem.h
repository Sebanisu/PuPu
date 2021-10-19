#ifndef FILESYSTEM_H
 #define FILESYSTEM_H
 
#include <string>
 
 
 
 class FileSystem
 {
 public:
                          FileSystem();
     virtual             ~FileSystem();
 
     virtual unsigned int GetFileSize(const std::string &path);
     virtual bool         ReadFile(const std::string &path, void* buffer, const unsigned int start, const unsigned int length);
             bool         WriteFile(const std::string &path, const void* buffer, const unsigned int length);
             bool         WriteNewFile(const std::string &path, const void* buffer, const unsigned int length);
             bool         RemoveFile(const std::string &path);
 };
 
 
 
 extern FileSystem *FILESYSTEM;
 
 
 
 #endif // FILESYSTEM_H
