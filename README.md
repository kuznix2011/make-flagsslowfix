# make-flagslowfix

A Pacman package that automatically adjusts `make -j` flags based on system resources:

- For systems with **4GB RAM + 16GB swap** and a **5400 RPM HDD**, large projects (>1GB) will use `-j2` instead of `-j4`.
- Small projects (<1GB) still use `-j4`.
- Detects CPU cores, RAM, swap, and HDD/SSD.
- Avoids altering flags for SSDs or high-RAM/high-core systems.
