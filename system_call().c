#include <iostream>
#include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 using namespace std;
int main() {
const char* filename = "example.txt"; // Replace with your file int fd = open(filename, O_RDONLY);

if(fd==-1) {
cout << "Error: Failed to open file '" << filename << "'" << endl; return 1;
}
struct stat file_info;
if (fstat(fd, &file_info) == -1) {
cout << "Error: System call failed to retrieve file information" << endl;
close(fd);
return 1;
}

cout << "File Type & Permissions: " << file_info.st_mode << endl; cout << "Inode Number: " << file_info.st_ino << endl;
cout << "Device ID: " << file_info.st_dev << endl;
cout << "Number of Hard Links:"<<file_info.st_nlink<<endl;
cout << "User ID of Owner: "<<file_info.st_uid<<endl;
cout << "Group ID of Owner: "<<file_info.st_gid<<endl;
cout << "File Size (bytes): " << file_info.st_size << endl; cout << "Last Access Time:"<<file_info.st_atime<<endl;
cout << "Last Modification Time: " << file_info.st_mtime << endl;

close(fd); return 0;
}
