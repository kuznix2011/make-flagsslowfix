#include <iostream>
#include <fstream>
#include <string>
#include <sys/statvfs.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    int jobs = 4; // default
    int cores = sysconf(_SC_NPROCESSORS_ONLN);

    struct sysinfo info;
    sysinfo(&info);
    long ramGB = info.totalram / (1024*1024*1024);
    long swapGB = info.totalswap / (1024*1024*1024);

    // Estimate project size
    system("du -s -B1 . > /tmp/project_size.tmp");
    std::ifstream f("/tmp/project_size.tmp");
    long long projectSize = 0;
    if(f.is_open()) {
        f >> projectSize;
        f.close();
    }

    // Check if root filesystem is HDD (simple heuristic)
    struct statvfs vfs;
    statvfs("/", &vfs);
    unsigned long blockSize = vfs.f_bsize;
    unsigned long totalSize = vfs.f_blocks * blockSize;
    bool isHDD = totalSize > (500LL*1024*1024*1024); // >500GB = HDD

    // Decide job count
    if(isHDD && ramGB <= 4 && swapGB <= 16 && projectSize > 1024*1024*1024) {
        jobs = 2;
    } else if(cores >= 12 && ramGB >= 16) {
        jobs = cores;
    }

    std::cout << "Recommended make -j" << jobs << std::endl;
    return 0;
}
